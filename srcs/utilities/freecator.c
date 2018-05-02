/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freecator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:30:54 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 15:31:15 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display.h"
#include "linked_list_itf.h"
#include "setting.h"
#include "ft_string.h"
#include "utilities.h"

void			free_(void *to_find)
{
	void		*tmp;
	t_ll_itf	*itf;

	if (!(tmp = locate_data_zone(to_find)))
		return ;
	itf = tmp;
	itf->type = SUB_FREE_DATA;
}
