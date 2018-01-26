#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include "../libft/libft.h"
# include <sys/mman.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

# define  FREE 0
# define  USED 1

# define  TYPE_TINY 0
# define  TYPE_SMALL 1
# define  TYPE_LARGE 2

# define  TINY   16
# define  SMALL  512
# define  TINY_BLOCK_SIZE sizeof(t_block_tiny)
# define  SMALL_BLOCK_SIZE sizeof(t_block_small)
# define  ALIGN_PAGE(x) ((((x - 1) >> 12) << 12) + getpagesize())

typedef struct s_block t_block;
typedef struct s_env t_env;

struct     s_block
{
  t_block  *next;
  size_t   size;
  bool     state;
};

struct    s_env
{
  t_block  *tiny;
  t_block  *small;
  t_block  *large;
  size_t   tiny_page_size;
  size_t   small_page_size;
  size_t   large_page_size;
};

void	*malloc(size_t size);
void  show_alloc_mem();

#endif
