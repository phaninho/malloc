/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2018/02/05 17:43:14 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

void	ft_utstr(char const *str)
{
	while (*str)
		write(1, str++, 1);
}

int		main(void)
{
	malloc(1024);
	malloc(1024 * 32);
	malloc(1024 * 1024);
	malloc(1024 * 1024 * 16);
	malloc(1024 * 1024 * 128);
	ft_putstr("\n---------show_alloc_mem()------------\n");
	show_alloc_mem();
	// ft_putstr("\n---------show_alloc_mem_ex()---------\n");
	// show_alloc_mem_ex();
	return (0);
}
