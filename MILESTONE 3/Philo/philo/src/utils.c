/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:33:22 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/13 18:52:49 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sig;
	int	num;

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
	return (num * sig);
}

int	ft_isdigit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	else
		return (0);
}
