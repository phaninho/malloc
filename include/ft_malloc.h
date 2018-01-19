#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include "../libft/libft.h"
# include <sys/mman.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define  TINY   16
# define  SMALL  512
# define  align4(x) (((((x) - 1) >> 2) << 2) + 4)

typedef struct     s_block
{
  struct s_block   *next;
  size_t           size;
  int              free;
}                  t_block;

void	*malloc(size_t size);

#endif
