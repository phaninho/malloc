#include "ft_malloc.h"

int     create_page(size_t size, t_block **block);

t_env		*init_env(void)
{
	static t_env  e = {NULL, 0};

	return (&e);
}

void     init_block(t_block *block, size_t size)
{
  block->size = size - sizeof(t_block);
  block->state = FREE;
  block->next = NULL;
}

int			init_page(t_env *e, t_block **block, int type_size)
{
	// t_block	*tmp;
	size_t	len;
	// tmp = *block;
	// while (*block && (*block)->next)
	// 	*block = (*block)->next;
	printf("[tiny_alloc] \n");
	len = ALIGN_PAGE((type_size + sizeof(t_block)) * 100);
	e->tiny_page_size += len;
	if (!(create_page(len, block)))
		return (1);
	// *block = tmp;
	return (0);
}
void	  *create_block(t_block *block, size_t size)
{
  t_block *next = NULL;;
  t_block *tmp;

  if (block && block->next)
  {
    tmp = block;
    int i = 0;
    while (tmp && tmp->next)
    {
      printf("next=>%d\n", i++);
      tmp = tmp->next;
    }
    next = tmp;
  }
  if (next && next->state == FREE && size < next->size)
  {
    printf("[create_block] assigne valeurs au next \n");
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
    printf("[create_block] initialise les valeurs du block. size vaux [%lu] et le next est situé [%p]\n", size, ((void*)block + sizeof(t_block) + size));
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
	// t_block *tmp;

	// tmp = NULL;
	// if (*block && (*block)->next)
  if ((*block = (void *)mmap(0, size, PROT_READ | PROT_WRITE,\
    MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
    return (0);
		// if ((tmp = (void *)mmap(0, size, PROT_READ | PROT_WRITE,\
	  //   MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
	  //   return (0);
		// printf(">>>>>>>>>>>>>>>[%p],[%p]<<<<<<<<<<< dif %d\n", *block, tmp, (int)tmp - (int)*block);
  init_block(*block, size);
  return (1);
}

void		*tiny_alloc(size_t size, t_env *e)
{
  void	*ptr = NULL;
	t_block *tmp = NULL;
//   if (e->tiny)
// printf("tiny size =>%lu\n", e->tiny->next->size);
	if (e->tiny && e->tiny->next)
	{
		tmp = e->tiny;
		while (tmp && tmp->next && tmp->next->next)
			tmp = tmp->next;
			printf("n-s[%lu]s-t_b[%lu]\n", tmp->size, sizeof(t_block));

	}
	if (tmp && tmp->next)
	printf("tms [%d] < sot_b [%d] || sot_b+s [%d]\n", (int)tmp->next->size, (int)sizeof(t_block), (int)sizeof(t_block) + (int)size);
  if (!(e->tiny) || (tmp && tmp->next && (int)tmp->next->size < (int)sizeof(t_block)) || (tmp && tmp->next && (int)tmp->next->size < (int)sizeof(t_block) + (int)size))
  {
		if (init_page(e, &(e)->tiny, TINY))
      return (NULL);
    printf("===><><><Nouvelle initialisation de page [%lu]\n", e->tiny->size);
  }
  if (e->tiny)
  {
    ptr = create_block(e->tiny, size);
    printf("diff entre e->tiny [%p] et retour de create_block [%p]\n", e->tiny, ptr);
    t_block *tmp = e->tiny;
    while (tmp->next->next)
      tmp = tmp->next;
    printf("block=>[%p] next=>[%p] diff=>%d missing space %lu[%d]\n", tmp, tmp->next, (int)tmp->next - (int)tmp, tmp->next->size, (int)tmp->next - (int)ptr);
  }
  return (ptr);
}

void		*malloc(size_t size)
{
	t_env   *e;
	void	  *ptr = NULL;
	t_block *tmp;

	printf("taille demandée %lu\n", size);
	e = init_env();
	if (size == 0)
		return (NULL);
	else
		ptr = tiny_alloc(size, e);
		tmp = e->tiny->next;

		while (tmp->next)
		tmp = tmp->next;
			printf("en sortie, la taille est a => [%lu]", tmp->size);

	return (ptr);
}
