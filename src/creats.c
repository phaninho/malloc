/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:55:40 by stmartin          #+#    #+#             */
/*   Updated: 2018/01/27 18:55:43 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	  *create_block(t_block *block, size_t size)
{
  t_block *next;
  t_block *tmp;

  printf("entree\n");

	next = NULL;
  if (block && block->next)
  {
    printf("1\n");
    tmp = block;
    while (tmp && tmp->next)
      tmp = tmp->next;
    next = tmp;
  }
  if (next && next->state == FREE && size < next->size)
  {
    printf("2\n");
    next->state = USED;
    printf("a\n");
    next->next = ((void*)next + sizeof(t_block) + size);
    printf("b %lu\n", next->size);
    next->next->state = FREE;
    printf("c\n");
    next->next->size = (int)next->size - (int)size - sizeof(t_block);
    printf("next->n->sz %lu\n", next->next->size);
    printf("d\n");
		next->next->next = NULL;
    printf("e\n");
    next->size = size;
    printf("sortie 2\n");
    return ((void*)next + sizeof(t_block));
  }
  else if (block && block->size > size)
  {
    printf("3\n");
    printf("block->sz %lu\n", block->size);

    block->state = USED;
    block->next = ((void*)block + sizeof(t_block) + size);
    block->next->state = FREE;
    block->next->size = (int)block->size - (int)size - sizeof(t_block);
    printf("block->n->sz %lu\n", block->next->size);
		block->next->next = NULL;
    block->size = size;
    printf("sortie 3\n");
		return ((void*)block + sizeof(t_block));
  }
  else if (next && size > next->size)
  {
    if (!(create_page(size, &next)))
      return (NULL);
    else
    {
      printf("ca va peter\n");
      return (create_block(next, size));
    }
  }
  else
    printf("la %zu\n", block->size);

	return (NULL);
}

int     create_page(size_t size, t_block **block)
{
  if ((*block = (void *)mmap(0, size, PROT_READ | PROT_WRITE,\
    MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
    return (0);
  init_block(*block, size);
  return (1);
}
