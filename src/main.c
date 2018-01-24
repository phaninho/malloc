
#include "../include/ft_malloc.h"

int   main()
{
  void *ptr;
  char *str;
  printf("==========debut===============\n");

  str = (char *)malloc(sizeof(char) * 8 + 1);
  str[8] = '\0';
  int i = 0;
  char a = '1';
  while (i < 9)
  {
    str[i] = a;
    a++;
    i++;
  }
  printf("str vaux=======>[%s][%p]\n", str, str);

    printf("address ptr[%p]\n", str);
    printf("len str[%lu]\n",strlen( ptr));
    printf("============fin=================\n\n");
    //
    // printf("==========debut===============\n");
    // str = (char*)malloc(sizeof(char) * 8);
    // str[7] = '\0';
    // i = 0;
    // a = 'a';
    // while (str && str[i])
    // {
    //   str[i] = a;
    //   a++;
    //   i++;
    // }
    // printf("str vaux=======>[%s]\n", str);

    // ptr = malloc(15);
    //   printf("address ptr[%p]\n", ptr);
    //   printf("len str[%lu]\n",strlen( ptr));
    //   printf("============fin=================\n\n");

    printf("==========debut===============\n");
    ptr = malloc(5);
      printf("address ptr[%p]\n", ptr);
      printf("len str[%lu]\n",strlen( ptr));
      printf("============fin=================\n\n");

  return (0);
}
