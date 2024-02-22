/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:55:54 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/22 18:29:02 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_images(t_fractol_data *f)
{
	draw_image(f);
	if (f->set == MANDELBROT && f->julia)
		draw_image(f->julia);
}

void	set_events_handlers(t_fractol_data *f)
{
	mlx_mouse_hook(f->win_ptr, mouse_handler_1, f);
	mlx_key_hook(f->win_ptr, keyboard_handler_1, f);
	mlx_hook(f->win_ptr, CLOSE_EVENT_NUMBER, 0, close_handler_1, f);
	if (f->set == MANDELBROT && f->julia)
	{
		mlx_mouse_hook(f->julia->win_ptr, mouse_handler_2, f->julia);
		mlx_key_hook(f->julia->win_ptr, keyboard_handler_2, f);
		mlx_hook(f->julia->win_ptr, CLOSE_EVENT_NUMBER, 0, close_handler_2,
			f);
	}
}

int	main(int argc, char const *argv[])
{
	t_fractol_data	f_data;

	if (argc == 1)
		display_help_exit(&f_data);
	init_fractol_data(&f_data);
	f_data.mlx_ptr = mlx_init();
	if (!f_data.mlx_ptr)
		clean_and_exit(&f_data, EXIT_FAILURE);
	parse_args(argc, argv, &f_data);
	create_colors_pallette(&f_data);
	init_mlx(&f_data);
	draw_images(&f_data);
	set_events_handlers(&f_data);
	mlx_loop(f_data.mlx_ptr);
	return (0);
}
