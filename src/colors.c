/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:49:44 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/22 20:57:05 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

void	interpolated_pallette(t_fractol_data *f)
{
	double	fraction;
	int		color1;
	int		color2;
	int		i;

	i = 0;
	while (i < MAX_ITERATIONS)
	{
		if ((i + 1) <= MAX_ITERATIONS / 2)
		{
			fraction = (double)(i + 1) / (MAX_ITERATIONS / 2);
			color1 = 0x000000;
			color2 = f->color;
		}
		else
		{
			fraction = (double)((i + 1) - MAX_ITERATIONS / 2)
				/ (MAX_ITERATIONS / 2);
			color1 = f->color;
			color2 = 0xFFFFFF;
		}
		f->pallette[i] = interpolate(color1, color2, fraction);
		i++;
	}
}

void	random_pallette(t_fractol_data *f)
{
	double	fraction;
	int		colors[5];
	int		i;
	int		j;
	int		x;

	i = 0;
	while (i < 5)
		colors[i++] = rand();
	i = 0;
	x = 0;
	while (i < MAX_ITERATIONS)
	{
		j = 0;
		while ((i + j) < MAX_ITERATIONS && j < (MAX_ITERATIONS / 5))
		{
			fraction = (double)j / (MAX_ITERATIONS / 5);
			f->pallette[i + j] = interpolate(colors[x], colors[x + 1],
					fraction);
			j++;
		}
		x++;
		i += j;
	}
}

int	get_color(int nb_iter, t_fractol_data *f)
{
	int		pallette_index;

	if (nb_iter == MAX_ITERATIONS)
		return (0);
	else
	{
		pallette_index = nb_iter + f->color_shift;
		if (pallette_index >= MAX_ITERATIONS)
			pallette_index = pallette_index - MAX_ITERATIONS;
		else if (pallette_index < 0)
			pallette_index = MAX_ITERATIONS + pallette_index;
	}
	return (f->pallette[pallette_index]);
}

void	create_colors_pallette(t_fractol_data *f)
{
	if (!f->pallette)
	{
		f->pallette = malloc(sizeof(int) * MAX_ITERATIONS);
		if (!f->pallette)
			clean_and_exit(f, EXIT_FAILURE);
		if (f->julia)
			f->julia->pallette = f->pallette;
	}
	interpolated_pallette(f);
}
