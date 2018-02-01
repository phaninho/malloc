/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:56:10 by stmartin          #+#    #+#             */
/*   Updated: 2018/01/27 18:56:12 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"


void		*large_alloc(size_t size, t_env *e)
{
  t_block   *tmp;

  tmp = NULL;
  if (e->large)
	{
		tmp = e->large;
		while (tmp && tmp->next)
        {
          if (tmp->state == FREE && tmp->size >= size)
          {
            tmp->state = USED;
            return ((void*)tmp + sizeof(t_block));
          }
          tmp = tmp->next;
        }
	}
  if (!(e->large))
  {
    if (init_page(e,  &(e)->large, size + sizeof(t_block), TYPE_LARGE))
      return (NULL);
    return (create_block(e->large, size));
  }
  else if (tmp && tmp->size < size)
  {
    if (init_page(e,  &tmp, size + sizeof(t_block), TYPE_LARGE))
        return (NULL);
      return (create_block(tmp, size));
  }
  return (create_block(tmp, size));
}

void		*small_alloc(size_t size, t_env *e)
{
  void	*ptr = NULL;
	t_block *tmp = NULL;

	if (e->small && e->small->next)
	{
		tmp = e->small;
		while (tmp && tmp->next && tmp->next->next)
			tmp = tmp->next;
	}
  if (!(e->small) || (tmp && tmp->next && \
    (int)tmp->next->size < (int)sizeof(t_block) + (int)size))
		if (init_page(e, tmp ? &tmp->next : &(e)->small, SMALL, TYPE_SMALL))
      return (NULL);
  if (e->small)
    ptr = create_block(e->small, size);
  return (ptr);
}

void		*tiny_alloc(size_t size, t_env *e)
{
  void	*ptr = NULL;
	t_block *tmp = NULL;

	if (e->tiny && e->tiny->next)
	{
		tmp = e->tiny;
		while (tmp && tmp->next && tmp->next->next)
			tmp = tmp->next;
	}
  if (!(e->tiny) || (tmp && tmp->next && (int)tmp->next->size < (int)sizeof(t_block) + (int)size))
  {
		if (init_page(e, tmp ? &tmp->next : &(e)->tiny, TINY, TYPE_TINY))
      return (NULL);
  }
  if (e->tiny)
    ptr = create_block(e->tiny, size);
  return (ptr);
}

void		*malloc(size_t size)
{
	t_env   *e;
	void	  *ptr;

	e = init_env();
	if (size == 0)
		return (NULL);
	if (size <= TINY)
		ptr = tiny_alloc(size, e);
	else if (size <= SMALL)
		ptr = small_alloc(size, e);
	else
		ptr = large_alloc(size, e);
	return (ptr);
}
