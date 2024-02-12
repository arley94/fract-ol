/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 08:47:19 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/16 09:48:57 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom(t_zoom zoom, t_fractol_data *f)
{
	if (zoom == ZOOM_IN)
	{
		f->r_span = f->r_span / 2;
		f->i_span = f->i_span / 2;
	}
	else if (zoom == ZOOM_OUT)
	{
		f->r_span = f->r_span * 2;
		f->i_span = f->i_span * 2;
	}
	set_copmplex_square(f);
	draw_image(f);
}
