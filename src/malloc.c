#include "ft_malloc.h"


void		*large_alloc(size_t size, t_env *e)
{
  void	*ptr = NULL;

  if (!(e->large))
  {
		if (init_page(e, &(e)->large, size + sizeof(t_block), TYPE_LARGE))
      return (NULL);
  }
  if (e->large)
    ptr = create_block(e->large, size);
  return (ptr);
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
  if (!(e->small) || (tmp && tmp->next && (int)tmp->next->size < (int)sizeof(t_block) + (int)size))
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
	void	  *ptr = NULL;
	t_block *tmp;
int type;

	e = init_env();
	if (size == 0)
		return (NULL);
	else if (size <= TINY)
	{
		ptr = tiny_alloc(size, e);
		type = TYPE_TINY;
	}
	else if (size <= SMALL)
	{
		ptr = small_alloc(size, e);
		type = TYPE_SMALL;
	}
	else
	{
		ptr = large_alloc(size, e);
		type = TYPE_LARGE;
	}
	tmp = e->tiny->next;
	return (ptr);
}
