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

static const char	*skip_ws_sign(const char *s, int *sign)
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
	return (s);
}

static double	parse_fraction(const char *s, t_atod *atod)
{
	atod->frac = 0.0;
	atod->base = 1.0;
	if (*s != '.')
		return (0.0);
	s++;
	while (ft_isdigit(*s))
	{
		atod->frac = atod->frac * 10.0 + (*s - '0');
		atod->base *= 10.0;
		s++;
	}
	return (atod->frac / atod->base);
}

double	ft_atod(const char *s, t_atod *atod)
{
	int	sign;

	sign = 1;
	atod->val = 0.0;
	atod->frac = 0.0;
	atod->point = 0;
	if (!s)
		return (0.0);
	atod->mary = skip_ws_sign(s, &sign);
	while (ft_isdigit(*atod->mary))
		atod->val = atod->val * 10.0 + (*atod->mary++ - '0');
	if (*atod->mary == '.')
	{
		atod->frac = parse_fraction(atod->mary, atod);
		atod->point = 1;
	}
	while ((*atod->mary == '.' && atod->point == 1) || ft_isdigit(*atod->mary))
		atod->mary++;
	if (*atod->mary != '\0')
	{
		ft_putstr_fd("err: wrong type of number", 2);
		exit(EXIT_FAILURE);
	}
	return (sign * (atod->val + atod->frac));
}
