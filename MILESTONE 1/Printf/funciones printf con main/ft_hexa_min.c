/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:28:01 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/05/20 19:10:54 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
//#include "libft.h"

int	ft_hexa_min(long int num)
{
	//long int	num;
	int			i;
	char		*base;

	base = "0123456789abcdef";
	//num = (long int)x;
	if (num < 0)
		num = -num;
	if (num >= 16)
		ft_hexa_min(num / 16);
	i = (num % 16);
	write(1, &base[i], 1);
	return (num);
}

//int	main(void)
//{
//	long int	n;

//	n = 45623;
//	ft_hexa_min(n);
//	return (0);
//}
