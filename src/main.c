#include "malloc.h"
#include <stdio.h>


void  *malloc(size_t size)
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
printf("t_block:%zu pagesize: %d\n", sizeof(t_block), getpagesize());
  str = NULL;
  if (ac > 2)
  {
    if (!(ft_strcmp("malloc", av[1])))
      str = malloc(ft_atoi(av[2]));
  }
  return (0);
}
