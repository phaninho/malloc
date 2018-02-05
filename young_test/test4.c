/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2018/02/01 17:43:47 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

void		print(char *s)
{
	write(1, s, strlen(s));
}

int			main(void)
{
	char	*addr;
	char	*test;

	addr = malloc(16);
	free(NULL);
	free((void *)addr + 5);
	test = realloc((void *)addr + 5, 10);
	if (test == NULL)
		print("Bonjours\n");
	return (0);
}
