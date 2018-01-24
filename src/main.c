
#include "../include/ft_malloc.h"

int   main()
{
  void *ptr;

  printf("==========debut===============\n");

  ptr = malloc(8);
  int i = 0;
  // while (i < 6000)
  // {
  //   str[i++] = 'q';
  //   printf("[%d]\n", i);
  // }
    printf("address ptr[%p]\n", ptr);
    printf("len str[%lu]\n",strlen( ptr));
    printf("============fin=================\n\n");

    printf("==========debut===============\n");
    ptr = malloc(15);
      printf("address ptr[%p]\n", ptr);
      printf("len str[%lu]\n",strlen( ptr));
      printf("============fin=================\n\n");

    printf("==========debut===============\n");
    ptr = malloc(5);
      printf("address ptr[%p]\n", ptr);
      printf("len str[%lu]\n",strlen( ptr));
      printf("============fin=================\n\n");

  return (0);
}
