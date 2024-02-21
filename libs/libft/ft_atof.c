/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoto-gu <acoto-gu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:28:19 by acoto-gu          #+#    #+#             */
/*   Updated: 2024/02/21 07:14:07 by acoto-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_float(const char *nb)
{
	int		i;
	char	*point_ptr;

	if (ft_strchr_n(nb, '.') != 1)
		return (0);
	point_ptr = ft_strchr(nb, '.');
	if (point_ptr == nb || point_ptr == (nb + ft_strlen(nb) - 1))
		return (0);
	i = 0;
	while (nb[i])
	{
		if (!ft_isdigit(nb[i]) && nb[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

static int	set_sign(const char *nb, int *sign)
{
	int	i;

	i = 0;
	if (nb[0] == '-')
	{
		*sign = -1;
		i = 1;
	}
	else if (nb[0] == '+')
	{
		*sign = 1;
		i = 1;
	}
	return (i);
}

int	ft_atof(const char *nptr, double *nb)
{
	long double	tmp_nb;
	int			div;
	int			sign;
	int			i;

	i = set_sign(nptr, &sign);
	if (!check_float(nptr + i))
		return (0);
	tmp_nb = 0;
	div = 10;
	while (ft_isdigit(nptr[i]))
		tmp_nb = tmp_nb * 10 + (nptr[i++] - '0');
	i++;
	while (ft_isdigit(nptr[i]))
	{
		tmp_nb = tmp_nb + (double)(nptr[i++] - '0') / div;
		div = div * 10;
	}
	*nb = tmp_nb;
	return (1);
}
