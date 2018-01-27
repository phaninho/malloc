/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:56:43 by stmartin          #+#    #+#             */
/*   Updated: 2018/01/27 18:56:46 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include "../libft/libft.h"
# include <sys/mman.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

# define  FREE 0
# define  USED 1

# define  TYPE_TINY 0
# define  TYPE_SMALL 1
# define  TYPE_LARGE 2

# define  TINY   16
# define  SMALL  512
# define  TINY_BLOCK_SIZE sizeof(t_block_tiny)
# define  SMALL_BLOCK_SIZE sizeof(t_block_small)
# define  ALIGN_PAGE(x) ((((x - 1) >> 12) << 12) + getpagesize())

typedef struct s_block t_block;
typedef struct s_env t_env;

struct     s_block
{
  t_block  *next;
  size_t   size;
  bool     state;
};

struct    s_env
{
  t_block  *tiny;
  t_block  *small;
  t_block  *large;
  size_t   tiny_page_size;
  size_t   small_page_size;
  size_t   large_page_size;
};

void		free(void *ptr);
void    show_alloc_mem();
void    *malloc(size_t size);
void    *realloc(void *ptr, size_t size);
void	  *calloc(size_t nmemb, size_t size);

void	  *create_block(t_block *block, size_t size);
void    init_block(t_block *block, size_t size);
int     create_page(size_t size, t_block **block);
int			init_page(t_env *e, t_block **block, int type_size, int type);
t_env		*init_env();

#endif
