/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:55:40 by stmartin          #+#    #+#             */
/*   Updated: 2018/02/02 16:28:13 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		assign_block(t_block **block, size_t size)
{
	(*block)->state = USED;
	(*block)->next = ((void*)(*block) + sizeof(t_block) + size);
	(*block)->next->state = FREE;
	(*block)->next->size = (int)(*block)->size - (int)size - sizeof(t_block);
	(*block)->next->next = NULL;
	(*block)->size = size;
}

void	  *create_block(t_block *block, size_t size)
{
	t_block *next;
	t_block *tmp;

	next = NULL;
	tmp = NULL;
	if (block && block->next)
	{
		if ((block_search(block, size, &tmp)))
			return ((void*)tmp + sizeof(t_block));
		next = tmp;
	}
	if (next && next->state == FREE && size < next->size)
	{
		assign_block(&next, size);
		return ((void*)next + sizeof(t_block));
	}
	else if (block && block->size > size)
	{
		assign_block(&block, size);
		return ((void*)block + sizeof(t_block));
	}
	return (NULL);
}

int     create_page(size_t size, t_block **block)
{
	if ((*block = (void *)mmap(0, size, PROT_READ | PROT_WRITE,\
					MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (0);
	init_block(*block, size);
	return (1);
}
