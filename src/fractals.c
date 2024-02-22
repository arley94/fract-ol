/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 08:19:40 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/22 15:23:03 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;

	zr = cr;
	zi = ci;
	n = 0;
	while (n < MAX_ITERATIONS)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if ((zr2 + zi2) > 4.0)
			break ;
		zi = 2 * zr * zi + ci;
		zr = zr2 - zi2 + cr;
		n++;
	}
	return (n);
}

int	julia(double cr, double ci, double kr, double ki)
{
	int		n;
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;

	n = 0;
	zr = cr;
	zi = ci;
	while (n < MAX_ITERATIONS)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if ((zr2 + zi2) > 4)
			break ;
		zi = 2 * zr * zi + ki;
		zr = zr2 - zi2 + kr;
		n++;
	}
	return (n);
}

static double	ft_absolute_d(double nb)
{
	if (nb >= 0)
		return (nb);
	else
		return (-nb);
}

int	burning_ship(double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;

	zr = cr;
	zi = ci;
	n = 0;
	while (n < MAX_ITERATIONS)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if ((zr2 + zi2) > 4.0)
			break ;
		zi = 2 * ft_absolute_d(zr) * ft_absolute_d(zi) + ci;
		zr = zr2 - zi2 + cr;
		n++;
	}
	return (n);
}

int	burning_ship_flip(double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	zr2;
	double	zi2;

	zr = -cr;
	zi = -ci;
	n = 0;
	while (n < MAX_ITERATIONS)
	{
		zr2 = zr * zr;
		zi2 = zi * zi;
		if ((zr2 + zi2) > 4.0)
			break ;
		zi = 2 * ft_absolute_d(zr) * ft_absolute_d(zi) - ci;
		zr = zr2 - zi2 - cr;
		n++;
	}
	return (n);
}
