#include "../include/ft_malloc.h"

void    *calloc(size_t nmemb, size_t size)
{
  if (nmemb == 0 || size == 0)
    return (NULL);
  return (malloc(nmemb * size));
}
