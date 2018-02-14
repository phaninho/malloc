/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:55:45 by stmartin          #+#    #+#             */
/*   Updated: 2018/02/02 16:12:22 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int			free_by_type(t_block *block, void *ptr, int type)
{
	t_block	*tmp;

	tmp = block;
	while (tmp && tmp->next)
	{
		if ((void *)tmp + sizeof(t_block) == ptr)
		{
			if (tmp->state == USED)
			{
				tmp->state = FREE;
				if (type == TYPE_LARGE)
					munmap(tmp, tmp->size);
			}
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void		free(void *ptr)
{
	t_env		*e;
	int			ret;

	ret = 0;
	e = init_env();
	pthread_mutex_lock(&e->mut);
	if (!ptr)
	{
		pthread_mutex_unlock(&e->mut);
		return ;
	}
	if (e->tiny)
		ret = free_by_type(e->tiny, ptr, TYPE_TINY);
	if (e->small && ret == 0)
		ret = free_by_type(e->small, ptr, TYPE_SMALL);
	if (e->large && ret == 0)
		ret = free_by_type(e->large, ptr, TYPE_LARGE);
	pthread_mutex_unlock(&e->mut);
}
