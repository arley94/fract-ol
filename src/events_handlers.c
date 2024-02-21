/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 08:22:45 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/21 20:03:23 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mouse_handler(int button, int x, int y, void *param)
{
	if (button == SCROLL_UP)
		zoom(x, y, ZOOM_IN, (t_fractol_data *) param);
	else if (button == SCROLL_DOWN)
		zoom(x, y, ZOOM_OUT, (t_fractol_data *) param);
	return (0);
}

int	close_handler(void *param)
{
	clean_and_exit((t_fractol_data *)param, EXIT_SUCCESS);
	return (0);
}

int	keyboard_handler(int key_code, void *param)
{
	if (key_code == ESCAPE_KEY_CODE)
	{
		clean_and_exit((t_fractol_data *)param, EXIT_SUCCESS);
	}
	return (0);
}
