/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstcreate_push_ll_end.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:36:40 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 15:36:57 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list_itf.h"

void			push_elem_end(t_ll_itf **l, unsigned int size, short type)
{
	int			turn;
	t_ll_itf	*tmp;

	turn = 0;
	tmp = (*l);
	while (tmp && tmp->next)
	{
		turn++;
		tmp = tmp->next;
	}
	if (!tmp)
		*l = (void *)(lstcreate_elem_itf(size, type));
	else
		tmp->next = (void *)lstcreate_elem_itf(size, type);
}
