
#include "../include/ft_malloc.h"

int   main()
{
  void *ptr;
  char *str;
  printf("==========debut===============\n");

  str = (char *)malloc(sizeof(char) * 8);
  str[7] = '\0';
  int i = 0;
  char a = '0';
  while (i < 8)
  {
    str[i] = a;
    a++;
    i++;
  }
  printf("str vaux=======>[%s][%p]\n", str, str);

    printf("address ptr[%p]\n", str);
    printf("len str[%lu]\n",strlen(str));
    printf("============fin=================\n\n");

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
    str = (char *)malloc(sizeof(char) * 3991);
    str[3990] = '\0';
    i = 0;
    a = '0';
    while (i < 3990)
    {
      str[i] = a;
      a = a == '9'? '0' - 1 : a;
      a++;
      i++;
    }
    printf("str vaux=======>[%s][%p] et l'index est a [%d]\n", str, str, i);

      printf("address ptr[%p]\n", str);
      printf("len str[%lu]\n",strlen(str));
      printf("============fin=================\n\n");

    // printf("==========debut===============\n");
    // ptr = malloc(3990);
    //   printf("address ptr[%p]\n", ptr);
    //   printf("len str[%lu]\n",strlen( ptr));
    //   printf("============fin=================\n\n");

      printf("==========debut===============\n");
      ptr = malloc(40);
        printf("address ptr[%p]\n", ptr);
        printf("len str[%lu]\n",strlen( ptr));
        printf("============fin=================\n\n");

  return (0);
}
