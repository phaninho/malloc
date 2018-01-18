#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include "../libft/libft.h"
# include <sys/mman.h>

typedef struct s_block
{
    double d;
    int i;
    char c2[3];
    char c;
}              t_block;

void	*malloc(size_t size);

#endif
