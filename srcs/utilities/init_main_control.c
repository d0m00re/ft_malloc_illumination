/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhelson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 15:28:22 by alhelson          #+#    #+#             */
/*   Updated: 2018/03/18 15:28:27 by alhelson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

void	reset_control_run(t_control_run *r)
{
	r->pos = 0;
	r->elem = 0;
	r->actual_size = 0;
}

void	init_main_control(t_main_control *control)
{
	reset_control_run(&(control->mcr));
	reset_control_run(&(control->mcd));
	reset_control_run(&(control->scd));
}
