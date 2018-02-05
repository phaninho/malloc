//#include <stdlib.h>
//#include <unistd.h>
#include "./include/ft_malloc.h"

int main()
{
malloc(1024);
malloc(1024 * 32);
malloc(1024 * 1024);
malloc(1024 * 1024 * 16);
malloc(1024 * 1024 * 128);
ft_putstr("============================\n");
show_alloc_mem();
ft_putstr("============================\n");
// show_alloc_mem_ex();
return (0);
}
