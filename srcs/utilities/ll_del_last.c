#include "utilities.h"

/*
** we have no data in this tab, we delete this : 1
** 0 : data is present
*/

int is_empty_tab(t_ll_itf *list)
{
	t_ll_itf *o;
	unsigned int size;
	void *data;

	data = list;
	size = 0;
	while (list && size < list->size)
	{
		o = (data + size);
		if (!(o->type == MAIN_CHUNK_DATA || o->type == 4))
			return (0);
		size += 16;
	}
	return (1);
}

/*
** delete les elements vide
*/

int check_then_delete(t_ll_itf *last_end, t_ll_itf *end)
{
	if (is_empty_tab(end))
	{
		desalloc(end, end->size);
		last_end->next = 0;
		return (1);
	}
	return (0);
}

void iterate_ll(void *ptr)
{
	unsigned int deph;
	t_ll_itf *main;
	t_ll_itf *old;

	main = ptr;
	old = ptr;
	deph = 0;
	while(main)
	{
		ft_putstr("turn ....\n");
		old = main;
		main = main->next;
		if (old && main && !(main->next))
		{
			ft_putstr("ya ya ya ...\n");
			if (check_then_delete(main, main->next))
			{
				ft_putstr("free.\n");
				iterate_ll(ptr);
			}	
		}
		deph++;
	}
}

void ll_del_last(void)
{
	iterate_ll(g_alloc->tiny);
	iterate_ll(g_alloc->medium);
	iterate_ll(g_alloc->large);
}
