/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:24:57 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/05/20 19:07:52 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_hexa_max(long int num)
{
	//char		c;
	//long int	num;
	int			i;
	char		*base;

	//i = 0;
	base = "0123456789ABCDEF";
	//num = (long int)x;
	if (num < 0)
		num = -num;
	if (num >= 16)
		ft_hexa_max(num / 16);
	//c = (num % 16);
	//i = c;
	i = (num % 16);
	write(1, &base[i], 1);
	return (num);
}

int	main(void)
{
	long int	n;

	n = 45623;
	ft_hexa_max(n);
	return (0);
}