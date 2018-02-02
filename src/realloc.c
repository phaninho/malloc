/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:56:15 by stmartin          #+#    #+#             */
/*   Updated: 2018/02/02 16:42:21 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

int		search_all_type(t_block *block, void *ptr)
{
	while (block)
	{
		if (ptr == (void*)block + sizeof(t_block))
			return (0);
		block = block->next;
	}
	return (1);
}

int		search_block(t_env *e, void *ptr)
{
	if (e->tiny)
	{
		if (search_all_type(e->tiny, ptr) == 0)
			return (0);
	}
	if (e->small)
	{
		if (search_all_type(e->small, ptr) == 0)
			return (0);
	}
	if (e->large)
	{
		if (search_all_type(e->large, ptr) == 0)
			return (0);
	}
	return (1);
}

void	*realloc(void *ptr, size_t size)
{
	void	*tmp;
	t_env	*e;

	e = init_env();
	tmp = NULL;
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
	{
		ptr = malloc(size);
		return (ptr);
	}
	else if (ptr)
	{
		if (search_block(e, ptr))
			return (NULL);
		tmp = malloc(size);
		ft_strcpy(tmp, ptr);
		free(ptr);
	}
	return (tmp);
}
