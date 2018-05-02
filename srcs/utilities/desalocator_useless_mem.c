/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desalocator_useless_mem.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:44:10 by alhelson          #+#    #+#             */
/*   Updated: 2018/05/02 15:53:45 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

static void				init_struct_fucking_control(t_fucking_control *c,\
		void *begining)
{
	c->begining = begining;
	c->c_chunk_area = 0;
	c->c_free_area = 0;
}

/*
** parcourir la structure de reference principal
** update structure
** free dans le cas ou on a aucune zone  alloue chunk
*/

static int				is_empty_area(t_fucking_control *control)
{
	if (control->c_chunk_area == 0 && control->begining)
		return (1);
	return (0);
}

int						free_data_area(t_fucking_control *control)
{
	t_ll_itf			*i;
	unsigned int		c;
	void				*data;

	if (!is_empty_area(control))
		return (0);
	desalloc(control->begining->next, control->begining->size);
	c = 0;
	data = control->begining;
	i = data;
	while (c <= control->c_free_area)
	{
		i->type = 5;
		i = data + 16 * (1 + c);
		c++;
	}
	return (1);
}

void					main_desalocator(void *elem, size_t size_data,\
	t_fucking_control *control, unsigned int size)
{
	t_ll_itf			*i;
	t_ll_itf			*o;
	void				*data;

	data = elem;
	i = data;
	size_data++;
	while (i)
	{
		while (i && size < i->size)
		{
			o = (data + size);
			if (o->type == MAIN_CHUNK_DATA && is_empty_area(control))
				free_data_area(control);
			if (o->type == MAIN_CHUNK_DATA || o->type == MAIN_CHUNK_REF)
				init_struct_fucking_control(control, o);
			else if (o->type == SUB_CHUNK_DATA)
				control->c_chunk_area += 1;
			else if (o->type == SUB_FREE_DATA)
				control->c_free_area += 1;
			size += 16;
		}
		data = i->next;
		i = i->next;
	}
}

void					desalocator_useless_mem(void)
{
	t_fucking_control	control;

	init_struct_fucking_control(&control, 0);
	main_desalocator(g_alloc->tiny, SIZE_TINY_ZONE, &control, 0);
	main_desalocator(g_alloc->medium, SIZE_MEDIUM_ZONE, &control, 0);
	main_desalocator(g_alloc->large, SIZE_PAGE, &control, 0);
}
