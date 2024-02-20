/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:10:57 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/20 10:51:17 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_fractal_options(void)
{
	ft_printf("+===============  Available Fractals  ===============+\n");
	ft_printf("Which fractal would you like to view?\n");
	ft_printf("\tM - Mandelbrot\n");
	ft_printf("\tJ - Julia\n");
	ft_printf("\e[33mUsage example:\t./fractol <type>\n\t\t./fractol M\e[0m\n");
	ft_printf("\nFor Julia, you may specify starting values for the\n");
	ft_printf("initial fractal shape. Values must be between\n");
	ft_printf("-2.0 and 2.0 and must contain a decimal point.\n");
	ft_printf("\e[33mUsage example:\t");
	ft_printf("./fractol J\n\t\t./fractol J 0.285 0.01\e[0m\n");
}

void	print_color_options(void)
{
	ft_printf("\n+===============  Color Display  ====================+\n");
	ft_printf("Pick a display color by providing a hexadecimal code.\n");
	ft_printf("The hex color code must be formatted as RRGGBB:\n");
	ft_printf("\tWhite:\tFFFFFF\t\tBlack:\t000000\n");
	ft_printf("\tRed:\tFF0000\t\tGreen:\t00FF00\n");
	ft_printf("\tBlue:\t0000FF\t\tYellow:\tFFFF00\n");
	ft_printf("Other interesting colors:\n");
	ft_printf("\tPurple:\t9933FF\t\tOrange:\tCC6600\n");
	ft_printf("\tPink:\tFF3399\t\tTurquoise: 00FF80\t\n");
	ft_printf("\e[33mUsage example:\t");
	ft_printf("./fractol <type> <color>\n");
	ft_printf("\t\t./fractol M 0066FF\e[0m\n");
	ft_printf("\nFor Julia, you can only specify colors after\n");
	ft_printf("the starting values.\n");
	ft_printf("\e[33mUsage example:\t");
	ft_printf("./fractol J 0.285 0.01 CC6600\e[0m\n");
}

void	clean_and_exit(t_fractol_data *f, int status)
{
	if (f->mlx_ptr && f->img.img_ptr)
		mlx_destroy_image(f->mlx_ptr, f->img.img_ptr);
	if (f->mlx_ptr && f->win_ptr)
		mlx_destroy_window(f->mlx_ptr, f->win_ptr);
	if (f->mlx_ptr)
	{
		mlx_loop_end(f->mlx_ptr);
		mlx_destroy_display(f->mlx_ptr);
		free(f->mlx_ptr);
	}
	exit(status);
}

void	display_help_exit(void)
{
	print_fractal_options();
	print_color_options();
	exit(EXIT_FAILURE);
}
