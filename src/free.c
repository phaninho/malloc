#include "../include/ft_malloc.h"

void		free(void *ptr)
{
	t_block	*block;

	if (!ptr)
		return ;
	block = ptr - sizeof(t_block);

	if (block && block->state == USED)
		block->state = FREE;
}
