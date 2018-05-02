/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_del_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:54:53 by alhelson          #+#    #+#             */
/*   Updated: 2018/05/02 15:55:50 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

/*
** we have no data in this tab, we delete this : 1
** 0 : data is present
*/

int					is_empty_tab(void *list)
{
	t_ll_itf		*original;
	t_ll_itf		*o;
	unsigned int	size;
	void			*data;

	original = list;
	data = list;
	size = 0;
	while (list && size < original->size)
	{
		o = (data + size);
		if (!(o->type == MAIN_CHUNK_REF || o->type == 4 ||\
		(size > 50 && o->type == 0)))
			return (0);
		size += 16;
	}
	return (1);
}

/*
** delete les elements vide
*/

int					check_then_delete(t_ll_itf *last_end, t_ll_itf *end)
{
	if (is_empty_tab(end))
	{
		desalloc(end, end->size);
		last_end->next = 0;
		return (1);
	}
	return (0);
}

void				iterate_ll(void *ptr)
{
	int				ret;
	unsigned int	deph;
	t_ll_itf		*main;
	t_ll_itf		*old;

	main = ptr;
	old = ptr;
	deph = 0;
	if (!(main->next))
		return ;
	while (main)
	{
		if (deph && !(main->next))
		{
			if ((ret = check_then_delete(old, main)))
				return ;
		}
		old = main;
		main = main->next;
		deph++;
	}
}

void				ll_del_last(void)
{
	iterate_ll(g_alloc->tiny);
	iterate_ll(g_alloc->medium);
	iterate_ll(g_alloc->large);
}
