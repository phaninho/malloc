#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# define		align4(x) (((((x) - 1) >> 2) << 2) + 4)
# include "libft.h"
# include <sys/mman.h>

typedef struct no_align
{
    char c;
    double d;
    int i;
    char c2[3];
}	no_align;

typedef struct align
{
    double d;
    int i;
    char c2[3];
    char c;
}	align;

#endif
