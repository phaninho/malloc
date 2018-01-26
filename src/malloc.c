#include "ft_malloc.h"

int     create_page(size_t size, t_block **block);

t_env		*init_env(void)
{
	static t_env  e = {NULL, NULL, NULL, 0, 0, 0};

	return (&e);
}

void     init_block(t_block *block, size_t size)
{
  block->size = size - sizeof(t_block);
  block->state = FREE;
  block->next = NULL;
}

int			init_page(t_env *e, t_block **block, int type_size, int type)
{
	size_t	len;

	if (type != TYPE_LARGE)
		len = ALIGN_PAGE((type_size + sizeof(t_block)) * 100);
	else
		len = ALIGN_PAGE((type_size + sizeof(t_block)));

	if (type == TYPE_TINY)
		e->tiny_page_size += len;
	else if (type == TYPE_SMALL)
		e->small_page_size += len;
	else
		e->large_page_size += len;
	if (!(create_page(len, block)))
		return (1);
	return (0);
}

void	  *create_block(t_block *block, size_t size)
{
  t_block *next;
  t_block *tmp;

	next = NULL;
  if (block && block->next)
  {
    tmp = block;
    while (tmp && tmp->next)
      tmp = tmp->next;
    next = tmp;
  }
  if (next && next->state == FREE && size < next->size)
  {
    next->state = USED;
    next->next = ((void*)next + sizeof(t_block) + size);
    next->next->state = FREE;
    next->next->size = (int)next->size - (int)size - sizeof(t_block);
		next->next->next = NULL;
    next->size = size;
    return ((void*)next + sizeof(t_block));
  }
  else
  {
    block->state = USED;
    block->next = ((void*)block + sizeof(t_block) + size);
    block->next->state = FREE;
    block->next->size = (int)block->size - (int)size - sizeof(t_block);
		block->next->next = NULL;
    block->size = size;
		return ((void*)block + sizeof(t_block));
  }
	return (NULL);
}

int     create_page(size_t size, t_block **block)
{
  if ((*block = (void *)mmap(0, size, PROT_READ | PROT_WRITE,\
    MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
    return (0);
  init_block(*block, size);
  return (1);
}

void		*small_alloc(size_t size, t_env *e)
{
  void	*ptr = NULL;
	t_block *tmp = NULL;
	// printf("c'est un small\n");

	if (e->small && e->small->next)
	{
		tmp = e->small;
		while (tmp && tmp->next && tmp->next->next)
			tmp = tmp->next;
	}
  if (!(e->small) || (tmp && tmp->next && (int)tmp->next->size < (int)sizeof(t_block) + (int)size))
		if (init_page(e, &(e)->small, SMALL, TYPE_SMALL))
      return (NULL);
  if (e->small)
    ptr = create_block(e->small, size);
  return (ptr);
}

void		*tiny_alloc(size_t size, t_env *e)
{
  void	*ptr = NULL;
	t_block *tmp = NULL;
	// printf("c'est un tiny\n");

	if (e->tiny && e->tiny->next)
	{
		tmp = e->tiny;
		while (tmp && tmp->next && tmp->next->next)
			tmp = tmp->next;
	}
  if (!(e->tiny) || (tmp && tmp->next && (int)tmp->next->size < (int)sizeof(t_block) + (int)size))
  {
		if (init_page(e, &(e)->tiny, TINY, TYPE_TINY))
      return (NULL);
  }
  if (e->tiny)
    ptr = create_block(e->tiny, size);
  return (ptr);
}

void		*large_alloc(size_t size, t_env *e)
{
  void	*ptr = NULL;
	// printf("c'est un large\n");

  if (!(e->large))
  {
		if (init_page(e, &(e)->large, size + sizeof(t_block), TYPE_LARGE))
      return (NULL);
  }
  if (e->large)
    ptr = create_block(e->large, size);
  return (ptr);
}

void    show_alloc_mem()
{
	t_env			*e;
	t_block		*block;

	e = init_env();

	if (e->tiny)
	{
		block = e->tiny;
		printf("TINY : %p\n", block);
		printf("%p - %p : %lu octets\n", block, (void*)block + block->size, block->size);

		// printf("%p - %p : %d %lu octets\n", block + sizeof(t_block), block + sizeof(t_block) + block->size, ((int)(block->next) - (int)sizeof(t_block)) - (int)(block), block->size);
		while (block->next && block->next->next)
		{
			block = block->next;
			printf("%p - %p : %lu octets\n", block, (void*)block + block->size, block->size);
		}
	}
	if (e->small)
	{
		block = e->small;
		printf("SMALL : %p\n", block);
		printf("%p - %p : %lu octets\n", block, (void*)block + block->size, block->size);

		// printf("%p - %p : %d %lu octets\n", block + sizeof(t_block), block + sizeof(t_block) + block->size, ((int)(block->next) - (int)sizeof(t_block)) - (int)(block), block->size);
		while (block->next && block->next->next)
		{
			block = block->next;
			printf("%p - %p : %lu octets\n", block, (void*)block + block->size, block->size);
		}
	}
	if (e->large)
	{
		block = e->large;
		printf("LARGE : %p\n", block);
		printf("%p - %p : %lu octets\n", block, (void*)block + block->size, block->size);

		// printf("%p - %p : %d %lu octets\n", block + sizeof(t_block), block + sizeof(t_block) + block->size, ((int)(block->next) - (int)sizeof(t_block)) - (int)(block), block->size);
		while (block->next && block->next->next)
		{
			block = block->next;
			printf("%p - %p : %lu octets\n", block, (void*)block + block->size, block->size);
		}
	}
	// if (type == TYPE_TINY)
	// else if (type == TYPE_SMALL)
	// 	printf("SMALL : [%p]\n", ptr - sizeof(t_block));
	// else
	// 	printf("LARGE : [%p]\n", ptr - sizeof(t_block));
	// printf()

}

void		*malloc(size_t size)
{
	t_env   *e;
	void	  *ptr = NULL;
	t_block *tmp;
int type;

	e = init_env();
	if (size == 0)
		return (NULL);
	else if (size <= TINY)
	{
		ptr = tiny_alloc(size, e);
		type = TYPE_TINY;
	}
	else if (size <= SMALL)
	{
		ptr = small_alloc(size, e);
		type = TYPE_SMALL;
	}
	else
	{
		ptr = large_alloc(size, e);
		type = TYPE_LARGE;
	}
	tmp = e->tiny->next;
	return (ptr);
}

void		free(void *ptr)
{
	t_block	*block;

	if (!ptr)
		return ;
	block = ptr - sizeof(t_block);

	if (block && block->state == USED)
		block->state = FREE;
}
