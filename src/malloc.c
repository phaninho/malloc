#include "ft_malloc.h"

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
    printf("les passages suivant \n");
    next->state = USED;
    next->next = ((void*)next + sizeof(t_block) + size);
    next->next->state = FREE;
    next->next->size = (int)next->size - (int)size - sizeof(t_block);
    next->size = size;
    return ((void*)next);
  }
  else
  {
    printf("premier passage \n");
    block->state = USED;
    block->next = ((void*)block + sizeof(t_block) + size);
    block->next->state = FREE;
    block->next->size = (int)block->size - (int)size - sizeof(t_block);
    block->size = size;
  }
  return ((void*)block);
}

int     create_page(size_t size, t_block **block)
{
  if ((*block = (void *)mmap(0, size, PROT_READ | PROT_WRITE,\
    MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
    return (0);
  init_block(*block, size);
  return (1);
}

void		*tiny_alloc(size_t size, t_env *e)
{
  void	*ptr = NULL;

  if (!(e->tiny))
  {
    e->tiny_page_size = ALIGN_PAGE((TINY + sizeof(t_block)) * 100);
    if (!create_page(e->tiny_page_size, &e->tiny))
      return (NULL);
    // printf("e t s [%lu]\n", e->tiny->size);
  }
  if (e->tiny)
  {
    ptr = create_block(e->tiny, size);
    t_block *tmp = e->tiny;
    while (tmp->next->next)
      tmp = tmp->next;
    printf("block=>[%p] next=>[%p] diff=>%d missing space %lu\n", tmp, tmp->next, (int)tmp->next - (int)tmp, tmp->next->size);
  }
  return (ptr);
}

void		*malloc(size_t size)
{
  t_env   *e;
  void	  *ptr = NULL;

  e = init_env();
  if (size == 0)
    return (NULL);
  else
    ptr = tiny_alloc(size, e);
  return (ptr);
}
