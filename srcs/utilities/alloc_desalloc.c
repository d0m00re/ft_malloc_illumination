/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_desalloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 18:44:41 by alhelson          #+#    #+#             */
/*   Updated: 2018/05/01 18:44:58 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"
#include <sys/mman.h>

void	*alloc(size_t size)
{
	return (mmap(NULL, size, PROT_READ | PROT_WRITE,\
		MAP_ANON | MAP_PRIVATE, -1, 0));
}

int		desalloc(void *addr, size_t length)
{
	int	ret;

	ret = munmap(addr, length);
	return (ret);
}
