/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handlers_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:19:03 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/23 08:47:47 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_handler_2(int button, int x, int y, void *param)
{
	t_fractol_data	*f;

	f = param;
	if (button == SCROLL_UP)
		re_draw_zoom(x, y, ZOOM_IN, f);
	else if (button == SCROLL_DOWN)
		re_draw_zoom(x, y, ZOOM_OUT, f);
	return (0);
}

int	keyboard_handler_2(int key_code, void *param)
{
	t_fractol_data	*f;

	f = param;
	if (key_code == ESCAPE_KEY_CODE)
	{
		if (f->win_ptr == NULL)
			clean_and_exit(f, EXIT_SUCCESS);
		close_window(f->julia);
		free(f->julia);
		f->julia = NULL;
	}
	if (key_code == LEFT_KEY_CODE || key_code == RIGHT_KEY_CODE
		|| key_code == UP_KEY_CODE || key_code == DOWN_KEY_CODE)
		re_draw_move(key_code, f->julia);
	return (0);
}

int	close_handler_2(void *param)
{
	t_fractol_data	*f;

	f = param;
	if (f->win_ptr == NULL)
		clean_and_exit(f, EXIT_SUCCESS);
	close_window(f->julia);
	free(f->julia);
	f->julia = NULL;
	return (0);
}
