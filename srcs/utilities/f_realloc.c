/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_realloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:30:28 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 15:30:39 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include <string.h>

void		*realloc(void *ptr, size_t size)
{
	void	*p;

	if (!g_alloc)
		pre_allocation();
	p = 0;
	if (!ptr)
		p = malloc(size);
	else if (ptr && size == 0)
		free(ptr);
	else if (ptr && size)
		p = realloc_(ptr, size);
	return (p);
}
