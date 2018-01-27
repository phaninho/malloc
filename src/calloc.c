/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:55:27 by stmartin          #+#    #+#             */
/*   Updated: 2018/01/27 18:55:34 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

void    *calloc(size_t nmemb, size_t size)
{
  void	*ptr;

  if (nmemb == 0 || size == 0)
    return (NULL);
  ptr = malloc(nmemb * size);
  ft_memset(ptr, 0, nmemb * size);
  return (ptr);
}
