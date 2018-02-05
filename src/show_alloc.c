/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:56:19 by stmartin          #+#    #+#             */
/*   Updated: 2018/02/05 17:51:40 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

void		print_in_hexa(int nb)
{
	int		tmp;
	int		i;
	char	s[7];

	s[6] = '\0';
	i = 6;
	tmp = nb;
	while (i > 0)
	{
		i--;
		tmp = nb % 16;
		s[i] = tmp >= 10 ? tmp - 10 + 'A' : tmp + '0';
		nb /= 16;
	}
	ft_putstr("0x");
	ft_putstr(s);
}

void		print_addr(t_block *block, size_t *len, int type)
{
	if (type == TYPE_TINY)
		ft_putstr("TINY : ");
	else
		ft_putstr(type == TYPE_SMALL ? "SMALL : " : "LARGE : ");
	print_in_hexa((int)block);
	ft_putendl("");
	while (block->next)
	{
		*len += block->size;
		print_in_hexa((int)block + sizeof(t_block));
		ft_putstr(" - ");
		print_in_hexa((int)block + sizeof(t_block) + block->size);
		ft_putstr(" : ");
		ft_putnbr(block->size);
		ft_putstr(" octets");
		ft_putendl("");
		block = block->next;
	}
}

void		show_alloc_mem(void)
{
	t_env	*e;
	size_t	len;

	len = 0;
	e = init_env();
	pthread_mutex_lock(&e->mut);
	if (e->tiny)
		print_addr(e->tiny, &len, TYPE_TINY);
	if (e->small)
		print_addr(e->small, &len, TYPE_SMALL);
	if (e->large)
		print_addr(e->large, &len, TYPE_LARGE);
	if (len)
	{
		ft_putstr("Total : ");
		ft_putnbr(len);
		ft_putendl(" octets");
	}
	pthread_mutex_unlock(&e->mut);
}
