/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 14:14:32 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 23:49:16 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

static void			display_1(char *type, t_ll_itf *run)
{
	ft_putstr(type);
	ft_putstr(" : 0x");
	ft_putnbr_base_ui((unsigned int)(run->next), 16);
	ft_putstr("\n");
}

static void			display_2(t_ll_itf *run, size_t *nb_data)
{
	ft_putstr("\t0x");
	ft_putnbr_base_ui((unsigned int)(run->next), 16);
	ft_putstr(" - 0x");
	ft_putnbr_base_ui((unsigned int)(run->next + run->size - 1), 16);
	ft_putstr(" : ");
	ft_putnbr_ui(run->size);
	ft_putstr(" octets\n");
	*nb_data += 1;
}

void				view_alloc_mem(void *elem, char *type,\
size_t *nb_size_data, size_t *nb_data)
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
			if (o->type == MAIN_CHUNK_DATA)
				display_1(type, o);
			else if (o->type == SUB_CHUNK_DATA)
			{
				display_2(o, nb_data);
				*nb_size_data += o->size;
			}
			size += 16;
		}
		data = i->next;
		i = i->next;
	}
}

void				show_alloc_mem(void)
{
	size_t			size_total;
	size_t			nb_chunk;

	size_total = 0;
	nb_chunk = 0;
	view_alloc_mem(g_alloc->tiny, "TINY", &size_total, &nb_chunk);
	view_alloc_mem(g_alloc->medium, "MEDIUM", &size_total, &nb_chunk);
	view_alloc_mem(g_alloc->large, "LARGE", &size_total, &nb_chunk);
	ft_putstr("Total : ");
	ft_putnbr_ui(size_total);
	ft_putstr(" octets\n");
}
