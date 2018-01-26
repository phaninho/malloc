
#include "../include/ft_malloc.h"

int   main()
{
  void *ptr;
  char *str;
  char *str1;
  char *str2;
  char *str3;
  char *str4;

  str = (char *)malloc(sizeof(char) * 8);
  str[7] = '\0';
  int i = 0;
  char a = '0';
  while (i < 7)
  {
    str[i] = a;
    a++;
    i++;
  }
  // printf("==========debut===============\n");
  // printf("str vaux=======>[%s][%p]\n", str, str);
  // printf("address ptr[%p]\n", str);
  // printf("len str[%lu]\n",strlen(str));
  // printf("============fin=================\n\n");


  // printf("==========debut du free=============== \n");
  // free(str);
  // printf("============fin=================\n\n");


  str1 = (char *)malloc(sizeof(char) * 16);
  str1[15] = '\0';
  i = 0;
  a = '0';
  while (i < 15)
  {
    str1[i] = a;
    a = a == '9'? '0' - 1 : a;
    a++;
    i++;
  }
  // printf("==========debut===============\n");
  // printf("address ptr[%p]\n", str1);
  // printf("len str[%lu]\n",strlen( str1));
  // printf("============fin=================\n\n");


  str2 = (char *)malloc(sizeof(char) * 60);
  str2[59] = '\0';
  i = 0;
  a = '0';
  while (i < 59)
  {
    str2[i] = a;
    a = a == '9'? '0' - 1 : a;
    a++;
    i++;
  }
  // printf("==========debut===============\n");
  // printf("str vaux=======>[%s][%p] et l'index est a [%d]\n", str2, str2, i);
  // printf("address ptr[%p]\n", str2);
  // printf("len str[%lu]\n",strlen(str2));
  // printf("============fin=================\n\n");

  str3 = (char *)malloc(sizeof(char) * 1000);
  str3[999] = '\0';
  i = 0;
  a = '0';
  while (i < 999)
  {
    str3[i] = a;
    a = a == '9'? '0' - 1 : a;
    a++;
    i++;
  }


  str4 = (char *)malloc(sizeof(char) * 1000);
  str4[999] = '\0';
  i = 0;
  a = '0';
  while (i < 999)
  {
    str4[i] = a;
    a = a == '9'? '0' - 1 : a;
    a++;
    i++;
  }

  // printf("==========debut du free=============== \n");
  // free(str);
  // printf("============fin=================\n\n");

// printf("1:[%s] 2:[%s] 3:[%s] 4:[%s] 5:[%s]\n", str, str1, str2, str3, str4);
show_alloc_mem();
  return (0);
}
