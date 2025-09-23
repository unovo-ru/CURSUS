/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:43:28 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/23 16:41:34 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(char *str)
{
	long	i;
	long	sig;
	long	num;

	i = 0;
	sig = 1;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == '\r')
		|| (str[i] == '\f') || (str[i] == ' ')
		|| (str[i] == '\v'))
		i++;
	if (str[i] == '-')
	{
		sig = -sig;
		i++;
	}
	else if (str[i] == '+')
		i++;
	num = 0;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sig);
}
