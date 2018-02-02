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

void	*alloc_copy(t_env *e, void *ptr, size_t size)
{
	void	*tmp;

	if (search_block(e, ptr))
	{
		pthread_mutex_unlock(&e->mut);
		return (NULL);
	}
	pthread_mutex_unlock(&e->mut);
	tmp = malloc(size);
	pthread_mutex_lock(&e->mut);
	ft_strcpy(tmp, ptr);
	pthread_mutex_unlock(&e->mut);
	free(ptr);
	pthread_mutex_lock(&e->mut);
	return (tmp);
}

void	*realloc(void *ptr, size_t size)
{
	void	*tmp;
	t_env	*e;

	e = init_env();
	tmp = NULL;
	pthread_mutex_lock(&e->mut);
	if (size == 0)
	{
		pthread_mutex_unlock(&e->mut);
		free(ptr);
		return (NULL);
	}
	if (!ptr)
	{
		pthread_mutex_unlock(&e->mut);
		ptr = malloc(size);
		return (ptr);
	}
	else if (ptr)
		tmp = alloc_copy(e, ptr, size);
	pthread_mutex_unlock(&e->mut);
	return (tmp);
}
