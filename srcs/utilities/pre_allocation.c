/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_allocation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 17:05:31 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 23:54:24 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

void	update_control(t_control_run *control, unsigned int actual_size,\
void *pos, t_ll_itf *itf)
{
	control->actual_size = actual_size;
	control->pos = pos;
	control->elem = itf;
}

/*
**  1) create reference zone
**  2) create sub zone who contains reference data
*/

void	pre_allocation(void)
{
	g_alloc = alloc(sizeof(t_addr_alloc));
	g_alloc->tiny = (void *)lstcreate_elem_itf(SIZE_TINY, MAIN_CHUNK_REF);
	g_alloc->medium = (void *)lstcreate_elem_itf(SIZE_MEDIUM, MAIN_CHUNK_REF);
	g_alloc->large = (void *)lstcreate_elem_itf(SIZE_LARGE, MAIN_CHUNK_REF);
	add_main_chunk_data(g_alloc->tiny + SIZE_STRUCT_NEXT, SIZE_TINY_ZONE);
	add_main_chunk_data(g_alloc->medium + SIZE_STRUCT_NEXT, SIZE_MEDIUM_ZONE);
}
