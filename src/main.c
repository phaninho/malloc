#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/ft_malloc.h"

int   main(int ac, char **av)
{
  char  *str;
printf("t_block:%zu pagesize: %d\n", sizeof(char), getpagesize());
  if (av[1])
    printf("[%s]\n", av[1]);
  str = NULL;
  str = malloc(atoi(av[1]));
  printf("str[%p]\n", str);
  return (0);
}
