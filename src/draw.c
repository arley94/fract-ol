/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:36:52 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/22 15:25:48 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	my_mlx_pixel_put(t_img_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	interpolate(int startcolor, int endcolor, double fraction)
{
	int	start_rgb[3];
	int	end_rgb[3];

	start_rgb[0] = ((startcolor >> 16) & 0xFF);
	start_rgb[1] = ((startcolor >> 8) & 0xFF);
	start_rgb[2] = ((startcolor >> 0) & 0xFF);
	end_rgb[0] = ((endcolor >> 16) & 0xFF);
	end_rgb[1] = ((endcolor >> 8) & 0xFF);
	end_rgb[2] = ((endcolor >> 0) & 0xFF);
	start_rgb[0] = (end_rgb[0] - start_rgb[0]) * fraction + start_rgb[0];
	start_rgb[1] = (end_rgb[1] - start_rgb[1]) * fraction + start_rgb[1];
	start_rgb[2] = (end_rgb[2] - start_rgb[2]) * fraction + start_rgb[2];
	return (0xFF << 24 | start_rgb[0] << 16 | start_rgb[1] << 8 | start_rgb[2]);
}

static int	get_color(int nb_iter, t_fractol_data *f)
{
	double	fraction;
	int		color1;
	int		color2;

	if (nb_iter == MAX_ITERATIONS)
		return (0);
	else if ((nb_iter + 1) <= MAX_ITERATIONS / 2)
	{
		fraction = (double)(nb_iter + 1) / (MAX_ITERATIONS / 2);
		color1 = 0x000000;
		color2 = f->color;
	}
	else
	{
		fraction = (double)((nb_iter + 1) - MAX_ITERATIONS / 2)
			/ (MAX_ITERATIONS / 2);
		color1 = f->color;
		color2 = 0xFFFFFF;
	}
	return (interpolate(color1, color2, fraction));
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
