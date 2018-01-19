
#include "../include/ft_malloc.h"

int   main(int ac, char **av)
{
  char  *str;
printf("pagesize: %d\n", getpagesize());
  if (av[1])
  {
    printf("size => [%s]\n", av[1]);
    str = malloc(atoi(av[1]));
    printf("address str[%p]\n", str);
  }
  str = NULL;
  return (0);
}
