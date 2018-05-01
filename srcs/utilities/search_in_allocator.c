/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_allocator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:28:41 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 17:07:47 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include "ft_display.h"

/*
** find empalcement of the allocated data addr
*/

void				*search_in_elem(void *elem, void *to_find)
{
	unsigned int	size;
	t_ll_itf		*i;
	t_ll_itf		*o;
	void			*data;

	data = elem;
	i = data;
	while (i)
	{
		size = 0;
		while (i && size < i->size)
		{
			o = (data + size);
			if (o->type == SUB_CHUNK_DATA && o->next == to_find)
				return (o);
			size += 16;
		}
		data = i->next;
		i = i->next;
	}
	return (0);
}

/*
** localisation de la zone de data ovulut
*/

void				*locate_data_zone(void *to_find)
{
	void			*tmp[3];

	if ((tmp[0] = search_in_elem(g_alloc->tiny, to_find)))
		return (tmp[0]);
	if ((tmp[1] = search_in_elem(g_alloc->medium, to_find)))
		return (tmp[1]);
	if ((tmp[2] = search_in_elem(g_alloc->large, to_find)))
		return (tmp[2]);
	return (0);
}
