/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reallocator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:29:50 by alhelson          #+#    #+#             */
/*   Updated: 2018/04/30 23:08:49 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

size_t			ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

void			*realloc_(void *ptr, size_t size)
{
	t_ll_itf	*elem_find;
	t_ll_itf	*elem_alloc;
	size_t		c;
	size_t		min;

	c = 0;
	if (ptr && size == 0)
		free_(ptr);
	if ((ptr && size == 0) || !(elem_find = locate_data_zone(ptr)))
		return (0);
	if (elem_find->size == size)
		return (elem_find->next);
	if (!(elem_alloc = malloc(size)))
		return (0);
	min = ft_min(elem_find->size, size);
	while (c < min)
	{
		((char *)(elem_alloc))[c] = ((char *)(elem_find->next))[c];
		c++;
	}
	elem_find->type = SUB_FREE_DATA;
	return (elem_alloc);
}
