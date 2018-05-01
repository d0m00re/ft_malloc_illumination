/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manage.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:45:04 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 15:55:35 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_MANAGE_H
# define MEMORY_MANAGE_H

# include <sys/mman.h>
# include <unistd.h>

# define SIZE_PAGE				getpagesize()

# define NB_PAGE_TINY_REF		1
# define NB_PAGE_MEDIUM_REF		1
# define NB_PAGE_LARGE_REF		1

# define NB_PAGE_TINY_DATA		1
# define NB_PAGE_MEDIUM_DATA	1
# define NB_PAGE_LARGE_DATA 	1

/*
** deux type de zone:
** 1) zone qui a pour objectif de stiquer l adresse et differentes info
** sur les zones memoire que retournera malloc
** 2) zone utile du projet | adresse que l on retournera avec le malloc
** [ADRESSE NEXT ZONE][EMPLACEMENT][BEGIN][SIZE]
** ADRESSE NEXT ZONE : next zone de referencement
*/

typedef struct					s_memory_info
{
	void						*emplacement;
	short						begin;
	unsigned int				size;
}								t_memory_info;

typedef struct					s_first_zone
{
	void						*next;
	t_memory_info				info;
}								t_first_zone;

#endif
