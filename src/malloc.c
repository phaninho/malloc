#include "ft_malloc.h"
#include <stdio.h>

void      *st_alloc(size_t size)
{
  void     *str;

  str = NULL;
  if (size <= TINY)
  {
    printf("dans st_alloc\n");
    if ((str = (void *)mmap(0, size <= TINY ? TINY : SMALL, PROT_READ | PROT_WRITE, \
      MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
      return (NULL);
  }
  return (str);
}

void      *l_alloc(size_t size)
{
  printf("c'est un LARGE\n");
  void	   *str;

  str = NULL;
  if ((str = (void *)mmap(0, size, PROT_READ | PROT_WRITE, \
    MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
    return (NULL);
  return (str);
}

t_block   *init_block()
{
  static t_block   block;

  // block.next = NULL;
  // block.size = 0;
  // block.free = 0;
  return (&block);
}

void	    *malloc(size_t size)
{
  void     *str;
  t_block  *block;

  block = init_block();
  printf("dans la fonction malloc un t_block vaux [%zu]\n", sizeof(t_block));
  size = align4(size);
  printf("apres align8, size => [%zu]\n", size);
  if (size == 0)
    return (NULL);
  else if (size <= SMALL)
    str = st_alloc(size);
  else
    str = l_alloc(size);

  return (str);
}
