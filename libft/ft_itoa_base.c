/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:39:11 by stmartin          #+#    #+#             */
/*   Updated: 2018/02/02 17:40:06 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ex(int nb)
{
	if (nb >= 10)
		return (nb - 10 + 'A');
	return (nb + '0');
}

char		*ft_itoa_base(int value, int base)
{
	int		i = 0;
	char	*str;
	int		tmp = value > 0 ? value : -value;
	int		neg = 0;

	if (base < 2 || base > 16)
		return (NULL);
	if (value == INT_MIN && base == 10)
		return (ft_strdup("-2147483648"));
	while (tmp >= base)
	{
		tmp /= base;
		i++;
	}
	if (value < 0 && base == 10)
	{
		i++;
		neg++;
	}
	if (value < 0)
		value = -value;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		tmp = value % base;
		str[i] = ex(tmp);
		value /= base;
		i--;
		if (neg && i == 0)
			str[i--] = '-';
	}
	return (str);
}
