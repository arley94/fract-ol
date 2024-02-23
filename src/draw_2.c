/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 08:47:19 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/23 08:55:07 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	re_draw_shift_pallette(t_fractol_data *f)
{
	f->color_shift = rand() % MAX_ITERATIONS;
	if (f->julia)
		f->julia->color_shift = f->color_shift;
	draw_image(f);
}

void	re_draw_interpollated_pallete(t_fractol_data *f)
{
	f->color_shift = 0;
	if (f->julia)
		f->julia->color_shift = 0;
	f->color = rand();
	interpolated_pallette(f);
	draw_image(f);
}

void	re_draw_random_pallete(t_fractol_data *f)
{
	random_pallette(f);
	draw_image(f);
}

void	re_draw_change_fractal(t_fractol_data *f)
{
	if (f->set == BURNING_SHIP_FLIP)
		f->set = MANDELBROT;
	else
		f->set = f->set + 1;
	draw_image(f);
}
