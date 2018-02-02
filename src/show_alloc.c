/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:56:19 by stmartin          #+#    #+#             */
/*   Updated: 2018/02/02 22:36:15 by stmartin         ###   ########.fr       */
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

void		print_for_ex(struct tm instant)
{
	ft_putstr(" | Creation date : ");
	ft_putnbr(instant.tm_mday);
	ft_putstr("/");
	ft_putnbr(instant.tm_mon + 1);
	ft_putstr("/");
	ft_putnbr(instant.tm_year + 1900);
	ft_putstr("  ");
	ft_putnbr(instant.tm_hour);
	ft_putstr(":");
	ft_putnbr(instant.tm_min);
	ft_putstr(":");
	ft_putnbr(instant.tm_sec);
}

void		print_addr(t_block *block, size_t *len, int type, int ex)
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
		if (ex == 1)
			print_for_ex(block->instant);
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
		print_addr(e->tiny, &len, TYPE_TINY, 0);
	if (e->small)
		print_addr(e->small, &len, TYPE_SMALL, 0);
	if (e->large)
		print_addr(e->large, &len, TYPE_LARGE, 0);
	if (len)
	{
		ft_putstr("Total : ");
		ft_putnbr(len);
		ft_putendl(" octets");
	}
	pthread_mutex_unlock(&e->mut);
}

void		show_alloc_mem_ex(void)
{
	t_env	*e;
	size_t	len;

	len = 0;
	e = init_env();
	pthread_mutex_lock(&e->mut);
	if (e->tiny)
		print_addr(e->tiny, &len, TYPE_TINY, 1);
	if (e->small)
		print_addr(e->small, &len, TYPE_SMALL, 1);
	if (e->large)
		print_addr(e->large, &len, TYPE_LARGE, 1);
	if (len)
	{
		ft_putstr("Total : ");
		ft_putnbr(len);
		ft_putendl(" octets");
	}
	pthread_mutex_unlock(&e->mut);
}
