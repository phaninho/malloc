/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:56:04 by stmartin          #+#    #+#             */
/*   Updated: 2018/01/27 18:56:05 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

// printf("%s\n", s);
  // printf("==========debut du free=============== \n");
  // free(str);
  // printf("============fin=================\n\n");
  // free(str1);
  // str4 = realloc(str4, 0);
// t_env *e;
// e = init_env();
// t_block *b;
// b = e->tiny;
// while (b && b->next)
// {
//   printf("%d %lu ", b->state, b->size);
//   b = b->next;
// }
// b = e->small;
// while (b && b->next)
// {
//   printf("%d %lu ", b->state, b->size);
//   b = b->next;
// }
// b = e->large;
// while (b && b->next)
// {
//   printf("%d %lu ", b->state, b->size);
//   b = b->next;
// }
printf("1:[%s] 2:[%s] 3:[%s] 4:[%s] 5:[%s]\n", str, str1, str2, str3, str4);
  // show_alloc_mem();
  // i = 7;
  // a = '0';
  // char *p;
  // str1 = realloc(str1, 4);
// printf("{%s}\n",str1);
  // while (i < 333334)
  // {
  //   str[i] = a;
  //   a = a == '9'? '0' - 1 : a;
  //   a++;
  //   i++;
  // }
  // t_block *b = (t_block *)str;
  // printf("\n%s %d\n", str, b->state);
  return (0);
}
