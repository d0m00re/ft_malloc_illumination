/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_size_page.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:33:57 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 15:34:05 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

size_t	find_next_size_page(size_t data, size_t size_mult)
{
	int			v;

	v = data / size_mult + 1;
	return (v * size_mult);
}
