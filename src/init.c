/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:11:29 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/22 12:34:59 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fractol_data(t_fractol_data *f)
{
	f->img.addr = NULL;
	f->img.img_ptr = NULL;
	f->mlx_ptr = NULL;
	f->win_ptr = NULL;
	f->r_span = INITIAL_REAL_SPAN;
	f->i_span = INITIAL_REAL_SPAN * HEIGHT / WIDTH;
	f->kr = 0.353;
	f->ki = 0.288;
	f->color = 0x550066;
	f->min_r = INITIAL_CENTER_X - f->r_span / 2;
	f->max_i = INITIAL_CENTER_Y + f->i_span / 2;
	f->julia = NULL;
}

void	init_aux_fractol(t_fractol_data *f)
{
	f->set = MANDELBROT;
	f->julia = malloc(sizeof(t_fractol_data));
	if (!f->julia)
		clean_and_exit(f, EXIT_FAILURE);
	init_fractol_data(f->julia);
	f->julia->set = JULIA;
	f->julia->mlx_ptr = f->mlx_ptr;
}

void	init_mlx(t_fractol_data *f)
{
	if (f->set == MANDELBROT && f->julia)
		init_mlx(f->julia);
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, "Fractol");
	if (!f->win_ptr)
		clean_and_exit(f, EXIT_FAILURE);
	f->img.img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	if (!f->img.img_ptr)
		clean_and_exit(f, EXIT_FAILURE);
	f->img.addr = mlx_get_data_addr(f->img.img_ptr, &(f->img.bits_per_pixel),
			&(f->img.line_length), &(f->img.endian));
}
