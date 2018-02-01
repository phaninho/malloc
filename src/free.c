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

void		free_by_type(t_block *block, void *ptr)
{
	t_block	*tmp;

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

void		free(void *ptr)
{
	t_env		*e;

	e = init_env();
	if (!ptr)
		return ;
	if (e->tiny)
		free_by_type(e->tiny, ptr);
  if (e->small)
		free_by_type(e->small, ptr);
  if (e->large)
		free_by_type(e->large, ptr);
}
