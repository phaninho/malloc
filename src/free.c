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
