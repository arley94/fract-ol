/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handlers_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 08:22:45 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/22 20:09:05 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_handler_1(int button, int x, int y, void *param)
{
	t_fractol_data	*f;

	f = param;
	if (button == SCROLL_UP)
		zoom(x, y, ZOOM_IN, f);
	else if (button == SCROLL_DOWN)
		zoom(x, y, ZOOM_OUT, f);
	else if (button == LEFT_CLICK && f->julia)
	{
		f->julia->kr = f->min_r + x * f->r_span / (WIDTH - 1);
		f->julia->ki = f->max_i - y * f->i_span / (HEIGHT - 1);
		f->julia->r_span = f->r_span;
		f->julia->i_span = f->i_span;
		f->julia->min_r = f->min_r;
		f->julia->max_i = f->max_i;
		draw_image(f->julia);
	}
	return (0);
}

int	keyboard_handler_1(int key_code, void *param)
{
	t_fractol_data	*f;

	f = param;
	if (key_code == ESCAPE_KEY_CODE)
	{
		if (f->julia == NULL)
			clean_and_exit(f, EXIT_SUCCESS);
		close_window(param);
	}
	else if (key_code == LEFT_KEY_CODE || key_code == RIGHT_KEY_CODE
		|| key_code == UP_KEY_CODE || key_code == DOWN_KEY_CODE)
		move(key_code, f);
	else if (key_code == S_KEY_CODE)
		shift_pallette(f);
	else if (key_code == C_KEY_CODE)
		change_pallete(f);
	else if (key_code == R_KEY_CODE)
		generate_random_pallette(f);
	return (0);
}

int	close_handler_1(void *param)
{
	t_fractol_data	*f;

	f = param;
	if (f->julia == NULL)
		clean_and_exit(f, EXIT_SUCCESS);
	close_window(param);
	return (0);
}
