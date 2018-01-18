#include "ft_malloc.h"
#include <stdio.h>

void  *malloc(size_t size)
{
  char  *str;
  printf("dans la fonction malloc\n");
  if (!(str = (char *)mmap(0, size, PROT_READ | PROT_WRITE, \
    MAP_ANON | MAP_PRIVATE, -1, 0)))
    return (NULL);
  return (str);
}
