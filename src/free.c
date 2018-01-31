/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:55:45 by stmartin          #+#    #+#             */
/*   Updated: 2018/01/27 18:55:47 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void		free(void *ptr)
{
	t_env		*e;
	t_block	*block = NULL;
	t_block	*tmp = NULL;

	e = init_env();
	if (!ptr)
		return ;
	if (e->tiny)
		block = e->tiny;
	tmp = block;
	while (tmp && tmp->next)
	{
		if ((void *)tmp + sizeof(t_block) == ptr)
		{
			if (tmp->state == USED)
				tmp->state = FREE;
			break ;
		}
		tmp = tmp->next;
	}
  if (e->small)
		block = e->small;
	tmp = block;
	while (tmp && tmp->next)
	{
		if ((void *)tmp + sizeof(t_block) == ptr)
		{
			if (tmp->state == USED)
				tmp->state = FREE;
			break ;
		}
		tmp = tmp->next;
	}
  if (e->large)
		block = e->large;
	tmp = block;
	while (tmp && tmp->next)
	{
		if ((void *)tmp + sizeof(t_block) == ptr)
		{
			if (tmp->state == USED)
				tmp->state = FREE;
			break ;
		}
		tmp = tmp->next;
	}
}
