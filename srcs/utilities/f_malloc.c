/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_malloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:33:37 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 15:33:46 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

void		*malloc(size_t size)
{
	void	*addr;

	if (!g_alloc)
		pre_allocation();
	if (size == 0)
		addr = manage_alloc(16);
	else
	{
		addr = manage_alloc(size);
	}
	return (addr);
}
