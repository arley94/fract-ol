/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:55:54 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/20 08:48:57 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_fractol_data(t_fractol_data *f)
{
	f->set = MANDELBROT;
	f->img.addr = NULL;
	f->img.img_ptr = NULL;
	f->mlx_ptr = NULL;
	f->win_ptr = NULL;
	f->r_span = INITIAL_REAL_SPAN;
	f->i_span = INITIAL_REAL_SPAN * HEIGHT / WIDTH;
	f->r_center = INITIAL_CENTER_X;
	f->i_center = INITIAL_CENTER_Y;
	f->kr = 0.353;
	f->ki = 0.288;
	f->color = 0x550066;
}

void	ft_init_mlx(t_fractol_data *f)
{
	f->mlx_ptr = mlx_init();
	if (!f->mlx_ptr)
		clean_and_exit(f, EXIT_FAILURE);
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, "Fractol");
	if (!f->win_ptr)
		clean_and_exit(f, EXIT_FAILURE);
	f->img.img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	if (!f->img.img_ptr)
		clean_and_exit(f, EXIT_FAILURE);
	f->img.addr = mlx_get_data_addr(f->img.img_ptr, &(f->img.bits_per_pixel),
			&(f->img.line_length), &(f->img.endian));
}

int	main(int argc, char const *argv[])
{
	t_fractol_data	f_data;

	if (argc == 1)
		display_help_exit();
	init_fractol_data(&f_data);
	parse_args(argc, argv, &f_data);
	ft_init_mlx(&f_data);
	set_copmplex_square(&f_data);
	draw_image(&f_data);
	mlx_mouse_hook(f_data.win_ptr, mouse_handler, &f_data);
	mlx_key_hook(f_data.win_ptr, keyboard_handler, &f_data);
	mlx_hook(f_data.win_ptr, CLOSE_EVENT_NUMBER, 0, close_handler, &f_data);
	mlx_loop(f_data.mlx_ptr);
	return (0);
}
