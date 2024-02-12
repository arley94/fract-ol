/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 08:53:19 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/16 09:46:55 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	set_copmplex_square(t_fractol_data *f)
{
	f->min_r = f->r_center - f->r_span / 2;
	f->max_r = f->r_center + f->r_span / 2;
	f->min_i = f->i_center - f->i_span / 2;
	f->max_i = f->i_center + f->i_span / 2;
}

void	set_square_center(int x, int y, t_fractol_data *f)
{
	f->r_center = f->min_r + (double)x * (f->r_span) / (WIDTH - 1);
	f->i_center = f->max_i - (double)y * (f->i_span) / (HEIGHT - 1);
}
