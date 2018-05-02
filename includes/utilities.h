/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:48:09 by alhelson          #+#    #+#             */
/*   Updated: 2018/05/02 15:57:55 by alhelson         ###   ########.fr       */
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
** free control struct
*/

typedef struct		s_fucking_control
{
	t_ll_itf		*begining;
	size_t			c_chunk_area;
	size_t			c_free_area;
}					t_fucking_control;

/*
** alloc desalloc memories
*/

void				*alloc(size_t size);
int					desalloc(void *addr, size_t length);

/*
** core
*/

void				update_control(t_control_run *control,\
					unsigned int actual_size, void *pos, t_ll_itf *itf);

void				add_type_elem(t_ll_itf *emplacement, void *elem,\
					short type, size_t size);

int					add_main_chunk_data(t_ll_itf *emplacement,\
					size_t size);

void				pre_allocation(void);

size_t				find_next_size_page(size_t data, size_t size_mult);

void				reset_control_run(t_control_run *r);

void				init_main_control(t_main_control *control);

void				*alloc_new_zone(void *data, size_t size, size_t size_data);

void				*manage_alloc(size_t size);

void				free_(void *to_find);

void				*realloc_(void *ptr, size_t size);

/*
** search in allocator
*/

void				*search_in_elem(void *elem, void *to_find);

void				*locate_data_zone(void *to_find);

/*
** MAIN FUNCTION
*/

void				free(void *ptr);

void				*malloc(size_t size);

void				*realloc(void *ptr, size_t size);

void				show_alloc_mem(void);

/*
** DESALOCATOR
*/

void				desalocator_useless_mem(void);

void				view_area(void);

void				ll_del_last(void);

#endif
