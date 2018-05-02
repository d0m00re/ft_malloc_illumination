/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 14:15:33 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 23:52:27 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display.h"
#include "linked_list_itf.h"
#include "setting.h"
#include "ft_string.h"
#include "utilities.h"

static void		go_or_create_next_ref(t_main_control *control,\
	int *tmp, int *display, void **data)
{
	if (!(control->mcr.elem->size > control->mcr.actual_size + 16))
	{
		if (control->mcr.elem->next)
		{
			control->mcr.actual_size = 0;
			control->mcr.pos = control->mcr.elem->next;
			control->mcr.elem = control->mcr.pos;
			*tmp += 1;
		}
		else
		{
			push_elem_end(*data, SIZE_TINY, MAIN_CHUNK_REF);
			*display = 1;
		}
	}
}

void			*core_allocator(t_main_control *control, t_ll_itf *itf,\
	size_t size_data, size_t size)
{
	if (!(control->mcd.elem))
	{
		add_main_chunk_data(itf, size_data);
		update_control(&(control->mcd), 0, itf, itf);
	}
	else if ((int)control->mcd.elem->size -\
((int)control->mcd.actual_size + (int)size) < 0)
	{
		add_main_chunk_data(itf, size_data);
		update_control(&(control->mcd), 0, itf, itf);
	}
	else
	{
		itf->type = SUB_CHUNK_DATA;
		itf->size = size;
		itf->next = control->mcd.elem->next + control->mcd.actual_size;
		return (itf->next);
	}
	return (0);
}

void			core_encaps_elem(t_ll_itf *itf,\
t_main_control *control)
{
	if (itf->type == MAIN_CHUNK_DATA)
		update_control(&(control->mcd), 0, itf, itf);
	else if (itf->type == SUB_CHUNK_DATA)
		control->mcd.actual_size += itf->size;
}

void			*alloc_new_zone(void *data, size_t size, size_t size_data)
{
	t_ll_itf		*itf;
	t_main_control	control;
	int				display;
	int				tmp;

	init_main_control(&control);
	update_control(&(control.mcr), 0, data, data);
	display = 0;
	tmp = 0;
	while (42)
	{
		while (control.mcr.actual_size + 16 < control.mcr.elem->size)
		{
			control.mcr.actual_size += SIZE_STRUCT_NEXT;
			itf = (t_ll_itf *)(control.mcr.pos + control.mcr.actual_size);
			core_encaps_elem(itf, &control);
			if (itf->type == EMPTY || itf->type == 4)
			{
				if (core_allocator(&control, itf, size_data, size))
					return (itf->next);
			}
		}
		go_or_create_next_ref(&control, &tmp, &display, &data);
	}
	return (0);
}

void			*manage_alloc(size_t size)
{
	void		*alloc_addr;

	if (size <= SIZE_TINY_DATA)
		alloc_addr = alloc_new_zone(g_alloc->tiny, size, SIZE_TINY_ZONE);
	else if (size <= SIZE_MEDIUM_DATA)
	{
		alloc_addr = alloc_new_zone(g_alloc->medium, size, SIZE_MEDIUM_ZONE);
	}
	else
	{
		alloc_addr = alloc_new_zone(g_alloc->large,\
		size, find_next_size_page(size, (size_t)SIZE_PAGE));
	}
	return (alloc_addr);
}
