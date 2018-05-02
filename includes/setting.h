/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:46:19 by alhelson          #+#    #+#             */
/*   Updated: 2018/04/30 19:11:46 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTING_H
# define SETTING_H

# include <unistd.h>

# define SIZE_PAGE			getpagesize()

# define NB_PAGE_TINY		50
# define NB_PAGE_MEDIUM		50
# define NB_PAGE_LARGE		50

# define SIZE_TINY			NB_PAGE_TINY * SIZE_PAGE
# define SIZE_MEDIUM		NB_PAGE_MEDIUM * SIZE_PAGE
# define SIZE_LARGE			NB_PAGE_LARGE * SIZE_PAGE

# define SIZE_TINY_ZONE		SIZE_PAGE
# define SIZE_MEDIUM_ZONE	SIZE_PAGE

# define SIZE_TINY_DATA		128
# define SIZE_MEDIUM_DATA	1024

typedef struct	s_addr_alloc
{
	void		*tiny;
	void		*medium;
	void		*large;
}				t_addr_alloc;

t_addr_alloc	*g_alloc;

#endif
