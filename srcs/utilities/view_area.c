/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_area.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 15:40:05 by alhelson          #+#    #+#             */
/*   Updated: 2018/05/02 15:41:27 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

static void			view_one_area(void *elem, size_t size_data)
{
	unsigned int	size;
	t_ll_itf		*i;
	t_ll_itf		*o;
	void			*data;

	data = elem;
	i = data;
	size_data++;
	while (i)
	{
		size = 0;
		while (i && size < i->size)
		{
			o = (data + size);
			if (o->type == MAIN_CHUNK_REF)
				ft_putstr("\n");
			else if (o->type == MAIN_CHUNK_DATA)
				ft_putstr("\n\t");
			ft_putnbr(o->type);
			ft_putchar(' ');
			size += 16;
		}
		data = i->next;
		i = i->next;
	}
}

void				view_area(void)
{
	ft_putstr("\ntiny : ");
	view_one_area(g_alloc->tiny, SIZE_TINY_ZONE);
	ft_putstr("\nmedium : ");
	view_one_area(g_alloc->medium, SIZE_MEDIUM_ZONE);
	ft_putstr("\nlarge : ");
	view_one_area(g_alloc->large, SIZE_PAGE);
}
