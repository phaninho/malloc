/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:55:57 by stmartin          #+#    #+#             */
/*   Updated: 2018/01/27 18:55:59 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_env		*init_env(void)
{
	static t_env  e = {NULL, NULL, NULL, 0, 0, 0};

	return (&e);
}

void     init_block(t_block *block, size_t size)
{
  block->size = size - sizeof(t_block);
  block->state = FREE;
  block->next = NULL;
}

int			init_page(t_env *e, t_block **block, int type_size, int type)
{
	size_t	len;

	if (type != TYPE_LARGE)
		len = ALIGN_PAGE((type_size + sizeof(t_block)) * 100);
	else
		len = ALIGN_PAGE((type_size + sizeof(t_block)));

	if (type == TYPE_TINY)
		e->tiny_page_size += len;
	else if (type == TYPE_SMALL)
		e->small_page_size += len;
	else
		e->large_page_size += len;
	if (!(create_page(len, block)))
		return (1);
	return (0);
}
