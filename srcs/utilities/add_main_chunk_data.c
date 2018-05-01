/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_main_chunk_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 14:12:21 by alhelson          #+#    #+#             */
/*   Updated: 2018/04/30 23:08:26 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include <sys/mman.h>

void		add_type_elem(t_ll_itf *emplacement,\
		void *elem, short type, size_t size)
{
	emplacement->next = elem;
	emplacement->type = type;
	emplacement->size = size;
}

/*
** gestion d uniquement des zone de type tiny pour le moment
** a juste pour objectif d ajouter la zone
** zone contenant la referecne vers le
** debut de la zone pouvant contenir des data
*/

int			add_main_chunk_data(t_ll_itf *emplacement,\
		size_t size)
{
	void	*new_area;

	if (!(new_area = alloc(size)))
		return (1);
	ft_bzero(new_area, size);
	add_type_elem(emplacement, new_area, MAIN_CHUNK_DATA, size);
	return (0);
}
