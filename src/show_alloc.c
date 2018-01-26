#include "ft_malloc.h"

void    show_alloc_mem()
{
	t_env			*e;
	t_block		*block;
	size_t		len;

	len = 0;
	e = init_env();

	if (e->tiny)
	{
		block = e->tiny;
		printf("TINY : %p\n", (void*)block - sizeof(t_block));
		printf("%p - %p : %lu octets\n", block, (void*)block + block->size, block->size);
		len += block->size;
		while (block->next && block->next->next)
		{
			block = block->next;
			len += block->size;
			printf("%p - %p : %lu octets\n", block, (void *)block + block->size, block->size);
		}
	}
	if (e->small)
	{
		block = e->small;
		printf("SMALL : %p\n", (void *)block - sizeof(t_block));
		printf("%p - %p : %lu octets\n", block, (void*)block + block->size, block->size);
		len += block->size;
		while (block->next && block->next->next)
		{
			block = block->next;
			len += block->size;
			printf("%p - %p : %lu octets\n", block, (void*)block + block->size, block->size);
		}
	}
	if (e->large)
	{
		block = e->large;
		printf("LARGE : %p\n", (void *)block - sizeof(t_block));
		printf("%p - %p : %lu octets\n", block, (void*)block + block->size, block->size);
		len += block->size;
		while (block->next && block->next->next)
		{
			block = block->next;
			printf("%p - %p : %lu octets\n", block, (void*)block + block->size, block->size);
			len += block->size;
		}
	}
	printf("Total : %lu octets\n", len);
}