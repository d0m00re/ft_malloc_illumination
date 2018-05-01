/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstcreate_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:36:10 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 15:36:37 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list_itf.h"
#include <sys/mman.h>
#include <string.h>

void			ft_bzero(void *s, size_t n)
{
	size_t		count;
	char		*str;

	count = 0;
	str = (char *)s;
	while (count < n)
	{
		str[count] = 0;
		count++;
	}
}

t_ll_itf		*lstcreate_elem_itf(unsigned int size, short type)
{
	t_ll_itf	*itf;

	itf = (t_ll_itf *)(mmap(NULL, size, PROT_READ | PROT_WRITE,\
		MAP_ANON | MAP_PRIVATE, -1, 0));
	ft_bzero((void *)itf, size);
	itf->size = size;
	itf->type = type;
	itf->next = 0;
	return (itf);
}
