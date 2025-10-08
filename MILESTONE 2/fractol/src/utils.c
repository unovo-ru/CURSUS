/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 19:59:01 by marvin            #+#    #+#             */
/*   Updated: 2025/10/05 19:59:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	skip_ws_sign(const char *s, int *sign)
{
	*sign = 1;
	while (*s < 33)
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			*sign = -1;
		s++;
	}
}

static double	parse_fraction(const char *s)
{
	double	frac;
	double	base;

	frac = 0.0;
	base = 1.0;
	if (*s != '.')
		return (0.0);
	while (ft_isdigit(*s))
	{
		frac = frac * 10.0 + (*s - '0');
		base *= 10.0;
		s++;
	}
	return (frac / base);
}

double	ft_atof(const char *s)
{
	int		sign;
	double	val;
	double	frac;

	val = 0.0;
	frac = 0.0;
	if (!s)
		return (0.0);
	skip_ws_sign(s, &sign);
	while (ft_isdigit(*s))
		val = val * 10.0 + (*s++ - '0');
	frac = parse_fraction(s);
	return (sign * (val + frac));
}
