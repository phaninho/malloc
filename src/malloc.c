#include "ft_malloc.h"
#include <stdio.h>

void    init_tiny_page(t_page_tiny *block)
{
  (void)block;
  // ft_memset(block, 0, TINY_BLOCK_SIZE);
}

void          *tiny_alloc(size_t size, t_page_tiny *block)
{
  (void)size;
  // ptr = NULL;
  init_tiny_page(block);
  printf("c'est un TINY\n");
  // if ((block = (void *)mmap(0, TINY_BLOCK_SIZE, PROT_READ | PROT_WRITE,
    //MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
    return (NULL);
  return (block);
}

void          *small_alloc(size_t size)
{
  void     *ptr;
(void)size;
  ptr = NULL;
  printf("c'est un SMALL\n");
  if ((ptr = (void *)mmap(0, SMALL_BLOCK_SIZE, PROT_READ | PROT_WRITE,\
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
  void          *ptr;
  t_page_tiny   *block;

  block = NULL;
  printf("MTS=>%zu, MSS=>%zu t_page_tiny=>[%zu]  t_page_small=>[%zu]\n", TINY_BLOCK_SIZE, SMALL_BLOCK_SIZE, sizeof(t_page_tiny), sizeof(t_page_small));
  size = align4(size);
  printf("apres align4, size => [%zu], small %d\n", size, SMALL);
  if (size == 0)
    return (NULL);
  else if(size <= TINY)
    ptr = tiny_alloc(size, block);
  else if (size <= SMALL)
    ptr = small_alloc(size);
  else
    ptr = large_alloc(size);
  return (ptr);
}
