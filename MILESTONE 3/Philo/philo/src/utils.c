/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:33:22 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/16 11:52:06 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sig;
	long	num;

	i = 0;
	sig = 1;
	while ((nptr[i] == ' ') || (nptr[i] == '\n') || (nptr[i] == '\r')
		|| (nptr[i] == '\f') || (nptr[i] == '\t')
		|| (nptr[i] == '\v'))
		i++;
	if (nptr[i] == '-')
		return (-1);
	else if (nptr[i] == '+')
		i++;
	num = 0;
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		num = (num * 10) + (nptr[i] - '0');
		i++;
	}
	if (num >= INT_MAX || num < 0)
		return (-1);
	return ((int)num * sig);
}

int	ft_isdigit_space(int c)
{
	if (((c >= 48) && (c <= 57)) || is_space(c))
		return (1);
	else
		return (0);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\f' || c == '\v')
		return (1);
	return (0);
}
