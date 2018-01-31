/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:56:15 by stmartin          #+#    #+#             */
/*   Updated: 2018/01/27 18:56:17 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_malloc.h"

void    *realloc(void *ptr, size_t size)
{
  void	  *tmp;
  t_env   *e;

  e = init_env();
  tmp = NULL;
  if (size == 0)
  {
    free(ptr);
    return (NULL);
  }
  if (!ptr)
  {
    ptr = malloc(size);
    return (ptr);
  }
  tmp = malloc(size);
  ft_strcpy(tmp, ptr);
  free(ptr);
  return (tmp);
}
