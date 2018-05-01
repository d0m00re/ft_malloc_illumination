/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_itf.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:42:29 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 15:54:55 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_ITF_H
# define LINKED_LIST_ITF_H

/*
** linkedlist interface
** structure la plus abstraite possible
** pour les futurs applications in le malloc
*/

typedef struct					s_ll_itf
{
	void						*next;
	short						type;
	unsigned int				size;
	void						*data;
}								t_ll_itf;

typedef struct					s_ll
{
	void						*next;
	short						type;
	unsigned int				size;
}								t_ll;

typedef struct					s_control_run
{
	void						*pos;
	t_ll_itf					*elem;
	unsigned int				actual_size;
}								t_control_run;

typedef struct					s_main_control
{
	t_control_run				mcr;
	t_control_run				mcd;
	t_control_run				scd;
}								t_main_control;

# define SIZE_STRUCT_NEXT		sizeof(t_ll)

/*
** ERROR : error data : i don t know
** MAIN_CHUNK_REF : zone qui contiendra
** les element MAIN_CHUNK_DATA  et SUB_CHUNK_DATA
** MAIN_CHUNK_DATA : element contenant le debut des elements
*/

enum							e_mabite{EMPTY,\
	MAIN_CHUNK_REF, MAIN_CHUNK_DATA, SUB_CHUNK_DATA, SUB_FREE_DATA};

t_ll_itf						*lstcreate_elem_itf(unsigned int size,\
		short type);

void							push_elem_end(t_ll_itf **l,\
		unsigned int size, short type);

#endif
