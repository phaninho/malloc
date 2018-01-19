#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include "../libft/libft.h"
# include <sys/mman.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

# define  TYPE_TINY 0
# define  TYPE_SMALL 1
# define  TYPE_LARGE 2

# define  TINY   16
# define  SMALL  512
# define  TINY_BLOCK_SIZE sizeof(t_block_tiny)
# define  SMALL_BLOCK_SIZE sizeof(t_block_small)
# define  align4(x) (((((x) - 1) >> 2) << 2) + 4)


typedef struct    s_block_tiny
{
  bool                state;
  char                id;
  char                type;
  char                data[TINY];
}                 t_block_tiny;

typedef struct    s_block_small
{
  bool                state;
  uint16_t            id;
  char                type;
  char                data[SMALL];
}                 t_block_small;

typedef struct    s_page_tiny
{
  struct s_page_tiny  *next;
  struct s_page_tiny  *prev;
  uint8_t             size;
  uint8_t             cur;
  t_block_tiny        table[256];
}                 t_page_tiny;

typedef struct    s_page_small
{
  struct s_page_small *next;
  struct s_page_small *prev;
  uint16_t            size;
  uint16_t            cur;
  t_block_small       table[65536];
}                 t_page_small;

void	*malloc(size_t size);

#endif
