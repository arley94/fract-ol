/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:46:08 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/22 14:54:24 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_str_is_hex(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && (str[i] < 'A' || str[i] > 'F'))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_atocolor(const char *rgb, int *color)
{
	int	i;
	int	nb;

	if (ft_strlen(rgb) != 6)
		return (0);
	if (!ft_str_is_hex(rgb))
		return (0);
	i = 0;
	nb = 0;
	while (rgb[i])
	{
		if (rgb[i] >= 'A' && rgb[i] <= 'F')
			nb = nb * 16 + 10 + (rgb[i] - 'A');
		else if (rgb[i] >= '0' && rgb[i] <= '9')
			nb = nb * 16 + (rgb[i] - '0');
		i++;
	}
	*color = nb;
	return (1);
}

void	parse_julia_values(int argc, const char *argv[], t_fractol_data *f)
{
	if (argc == 4)
	{
		if (!ft_atof(argv[2], &f->kr) || !ft_atof(argv[3], &f->ki))
			display_help_exit(f);
	}
	else if (argc == 5)
	{
		if (!ft_atof(argv[2], &f->kr) || !ft_atof(argv[3], &f->ki))
			display_help_exit(f);
		if (!ft_atocolor(argv[4], &f->color))
			display_help_exit(f);
	}
}

void	parse_others(int argc, const char *argv[], t_fractol_data *f)
{
	if (argc == 3)
	{
		if (!ft_atocolor(argv[2], &f->color))
			display_help_exit(f);
		if (f->julia)
			f->julia->color = f->color;
	}
}

void	parse_args(int argc, const char *argv[], t_fractol_data *f)
{
	if (ft_strncmp(argv[1], "M", 2) == 0)
		f->set = MANDELBROT;
	else if (ft_strncmp(argv[1], "J", 2) == 0)
		f->set = JULIA;
	else if (ft_strncmp(argv[1], "MJ", 3) == 0)
		init_aux_fractol(f);
	else if (ft_strncmp(argv[1], "B", 2) == 0)
		f->set = BURNING_SHIP;
	else
		display_help_exit(f);
	if (f->set == JULIA)
	{
		if (argc == 3 || argc > 5)
			display_help_exit(f);
		parse_julia_values(argc, argv, f);
	}
	else if (f->set == MANDELBROT)
	{
		if (argc > 3)
			display_help_exit(f);
		parse_others(argc, argv, f);
	}
}
