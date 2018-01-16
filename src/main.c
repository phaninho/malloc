#include "ft_malloc.h"
#include <stdio.h>


void  *ft_malloc(size_t size)
{
  char  *str;
  if (!(str = (char *)mmap(0, size, PROT_READ | PROT_WRITE, \
    MAP_ANON | MAP_PRIVATE, -1, 0)))
    return (NULL);
  return (str);
}

int   main(int ac, char **av)
{
  char  *str;
printf("no align:%zu align:%zu\n", sizeof(no_align), sizeof(align));
  str = NULL;
  if (ac > 2)
  {
    if (!(ft_strcmp("malloc", av[1])))
      str = ft_malloc(ft_atoi(av[2]));
  }
  return (0);
}
