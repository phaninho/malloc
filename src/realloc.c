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

int   search_block(t_env *e, void *ptr)
{
  t_block   *block;

  if (e->tiny)
  {
    block = e->tiny;
    while (block)
    {
      if (ptr == (void*)block + sizeof(t_block))
        return (0);
      block = block->next;
    }
  }
  if (e->small)
  {
    block = e->small;
    while (block)
    {
      if (ptr == (void*)block + sizeof(t_block))
        return (0);
      block = block->next;
    }
  }
  if (e->large)
  {
    block = e->large;
    while (block)
    {
      if (ptr == (void*)block + sizeof(t_block))
        return (0);
      block = block->next;
    }
  }
  return (1);
}

void    *realloc(void *ptr, size_t size)
{
  void	  *tmp;
  t_env   *e;
// printf("ici\n");
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
  else if (ptr)
  {
    if (search_block(e, ptr))
      return (NULL);
    tmp = malloc(size);
    ft_strcpy(tmp, ptr);
    free(ptr);
  }
  return (tmp);
}
