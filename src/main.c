#include "../include/ft_malloc.h"

int main()
{
  char *s;
  char *t;
  char *tt;
  char *ttt;
  char *tttt;
  char *ttttt;
  char *tttttt;



  s = (char *)malloc(sizeof(char) * 8);
  t = (char *)malloc(sizeof(char) * 8);
  tt = (char *)malloc(sizeof(char) * 18);
  ttt = (char *)malloc(sizeof(char) * 118);
  tttt = (char *)malloc(sizeof(char) * 128);
  ttttt = (char *)malloc(sizeof(char) * 1238);
  tttttt = (char *)malloc(sizeof(char) * 108);

  show_alloc_mem();
  return (0);
}
