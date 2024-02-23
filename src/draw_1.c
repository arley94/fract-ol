/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:36:52 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/23 08:54:54 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	my_mlx_pixel_put(t_img_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	calculate_fractal(t_fractol_data *f, double pr, double pi)
{
	int	nb_iter;

	if (f->set == MANDELBROT)
		nb_iter = mandelbrot(pr, pi);
	else if (f->set == JULIA)
		nb_iter = julia(pr, pi, f->kr, f->ki);
	else if (f->set == BURNING_SHIP)
		nb_iter = burning_ship(pr, pi);
	else if (f->set == BURNING_SHIP_FLIP)
		nb_iter = burning_ship_flip(pr, pi);
	return (nb_iter);
}

void	draw_image(t_fractol_data *f)
{
	int		x;
	int		y;
	double	z_r;
	double	z_i;
	int		nb_iter;

	mlx_clear_window(f->mlx_ptr, f->win_ptr);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			z_r = f->min_r + (double)x * (f->r_span) / (WIDTH - 1);
			z_i = f->max_i - (double)y * (f->i_span) / (HEIGHT - 1);
			nb_iter = calculate_fractal(f, z_r, z_i);
			my_mlx_pixel_put(&f->img, x, y, get_color(nb_iter, f));
		}
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img.img_ptr, 0, 0);
}

void	re_draw_zoom(int x, int y, t_zoom zoom, t_fractol_data *f)
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

void	re_draw_move(int direction, t_fractol_data *f)
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
