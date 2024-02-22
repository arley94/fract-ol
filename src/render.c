/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 08:47:19 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/22 14:20:39 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom(int x, int y, t_zoom zoom, t_fractol_data *f)
{
	if (zoom == ZOOM_IN)
	{
		f->r_span = f->r_span / 2;
		f->i_span = f->i_span / 2;
		f->min_r = f->min_r + f->r_span * x / (WIDTH - 1);
		f->max_i = f->max_i - f->i_span * y / (HEIGHT - 1);
	}
	else if (zoom == ZOOM_OUT)
	{
		f->r_span = f->r_span * 2;
		f->i_span = f->i_span * 2;
		f->min_r = f->min_r - f->r_span * x / (WIDTH - 1) / 2;
		f->max_i = f->max_i + f->i_span * y / (HEIGHT - 1) / 2;
	}
	draw_image(f);
}

void	move(int direction, t_fractol_data *f)
{
	if (direction == LEFT_KEY_CODE)
		f->min_r = f->min_r - (f->r_span / 10);
	else if (direction == RIGHT_KEY_CODE)
		f->min_r = f->min_r + (f->r_span / 10);
	else if (direction == UP_KEY_CODE)
		f->max_i = f->max_i + (f->i_span / 10);
	else if (direction == DOWN_KEY_CODE)
		f->max_i = f->max_i - (f->i_span / 10);
	draw_image(f);
}