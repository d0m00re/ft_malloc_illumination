/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:48:09 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 23:43:39 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include "linked_list_itf.h"
# include "setting.h"
# include "ft_string.h"
# include "ft_display.h"
# include <string.h>

/*
** alloc desalloc memories
*/

void			*alloc(size_t size);
int			desalloc(void *addr, size_t length);

/*
** core
*/

void			update_control(t_control_run *control,\
				unsigned int actual_size, void *pos, t_ll_itf *itf);

void			add_type_elem(t_ll_itf *emplacement, void *elem,\
				short type, size_t size);

int				add_main_chunk_data(t_ll_itf *emplacement,\
				size_t size);

void			pre_allocation(void);

size_t			find_next_size_page(size_t data, size_t size_mult);

void			reset_control_run(t_control_run *r);

void			init_main_control(t_main_control *control);

void			*alloc_new_zone(void *data, size_t size, size_t size_data);

void			*manage_alloc(size_t size);

void			free_(void *to_find);

void			*realloc_(void *ptr, size_t size);

/*
** search in allocator
*/

void			*search_in_elem(void *elem, void *to_find);

void			*locate_data_zone(void *to_find);

/*
** MAIN FUNCTION
*/

void			free(void *ptr);

void			*malloc(size_t size);

void			*realloc(void *ptr, size_t size);

void			show_alloc_mem(void);

/*
** DESALOCATOR
*/

void			desalocator_useless_mem(void);

void			view_area(void);

#endif
