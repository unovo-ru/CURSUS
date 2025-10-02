/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:25:33 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/05/02 19:04:29 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sig;
	int	num;

	i = 0;
	sig = 1;
	while ((nptr[i] == '\t') || (nptr[i] == '\n') || (nptr[i] == '\r')
		|| (nptr[i] == '\f') || (nptr[i] == ' ')
		|| (nptr[i] == '\v'))
		i++;
	if (nptr[i] == '-')
	{
		sig = -sig;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	num = 0;
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		num = (num * 10) + (nptr[i] - '0');
		i++;
	}
	return (num * sig);
}
