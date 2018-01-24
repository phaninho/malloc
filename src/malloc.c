#include "ft_malloc.h"
#include <stdio.h>

void    init_tiny_page(t_page_tiny *block, char type)
{
  unsigned int  len;
  unsigned int  i;

  i = -1;
  len = 0;

  if (type == TYPE_TINY)
    len = 256;
  block->next = NULL;
  block->prev = NULL;
  block->size = getpagesize();
  block->cur = 0;
  while (++i < len)
  {
    block->table[i].state = FREE;
    block->table[i].id = i;
    block->table[i].type = TYPE_TINY;
  }
}

void          *tiny_alloc(size_t size, t_page_tiny **block)
{
  size = ALIGN_PAGE(TINY + sizeof(t_block_small));

  printf("c'est un TINY %lu\n", size);
  if (!(*block))
  {
    if ((*block = (void *)mmap(0, size, PROT_READ | PROT_WRITE,
      MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
      return (NULL);
    init_tiny_page(*block, TYPE_TINY);
  }
  return (*block);
}

// void          *small_alloc(size_t size)
// {
//   void     *ptr;
// (void)size;
//   ptr = NULL;
//   printf("c'est un SMALL\n");
//   if ((ptr = (void *)mmap(0, SMALL_BLOCK_SIZE, PROT_READ | PROT_WRITE,\
//     MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
//     return (NULL);
//   return (ptr);
// }
//
// void          *large_alloc(size_t size)
// {
//   printf("c'est un LARGE\n");
//   void	   *ptr;
//
//   ptr = NULL;
//   if ((ptr = (void *)mmap(0, size, PROT_READ | PROT_WRITE, \
//     MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
//     return (NULL);
//   return (ptr);
// }

void	       *malloc(size_t size)
{
  static t_page_tiny   *block;

  // printf("MTS=>%zu, MSS=>%zu t_page_tiny=>[%zu]  t_page_small=>[%zu]\n", TINY_BLOCK_SIZE, SMALL_BLOCK_SIZE, sizeof(t_page_tiny), sizeof(t_page_small));
  // printf("apres alignpage, size => [%zu], small %d\n", size, SMALL);
  if (size == 0)
    return (NULL);
  else //if(size <= TINY)
    tiny_alloc(size, &block);
printf("size=>[%lu]",  sizeof(t_page_tiny));
printf("[%d]", (int)(sizeof(block->table))) ;
    // block->table[1].state = USED;
  // else if (size <= SMALL)
  //   ptr = small_alloc(size);
  // else
  //   ptr = large_alloc(size);
  return (block);
}
