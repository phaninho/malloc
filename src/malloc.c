#include "ft_malloc.h"
#include <stdio.h>

void    init_tiny_page(t_page_tiny *block)
{
  ft_memset(block, 0, sizeof(t_page_tiny));
}

void          *tiny_alloc(size_t size)
{
  void          *ptr;
  t_page_tiny   block;
(void)size;
  ptr = NULL;
  init_tiny_page(&block);
  printf("c'est un TINY\n");
  if ((ptr = (void *)mmap(0, TINY, PROT_READ | PROT_WRITE,\
    MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
    return (NULL);
  return (ptr);
}

void          *small_alloc(size_t size)
{
  void     *ptr;
(void)size;
  ptr = NULL;
  printf("c'est un SMALL\n");
  if ((ptr = (void *)mmap(0, SMALL, PROT_READ | PROT_WRITE,\
    MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
    return (NULL);
  return (ptr);
}

void          *large_alloc(size_t size)
{
  printf("c'est un LARGE\n");
  void	   *ptr;

  ptr = NULL;
  if ((ptr = (void *)mmap(0, size, PROT_READ | PROT_WRITE, \
    MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
    return (NULL);
  return (ptr);
}

void	       *malloc(size_t size)
{
  void     *ptr;
  //t_block  *block;

  printf("MTS=>%zu, MSS=>%zu t_page_tiny=>[%zu]  t_page_small=>[%zu]\n", META_SIZE_TINY, META_SIZE_SMALL, sizeof(t_page_tiny), sizeof(t_page_small));
  size = align4(size);
  printf("apres align4, size => [%zu], small %d\n", size, SMALL);
  if (size == 0)
    return (NULL);
  else if(size <= TINY)
    ptr = tiny_alloc(size);
  else if (size <= SMALL)
    ptr = small_alloc(size);
  else
    ptr = large_alloc(size);
  return (ptr);
}
