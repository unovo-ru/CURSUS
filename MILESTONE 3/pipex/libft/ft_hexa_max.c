/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:24:57 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/08/04 21:14:18 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexa_max(unsigned long long num)
{
	int			i;
	char		*base;
	int			count;

	count = 0;
	base = "0123456789ABCDEF";
	if (num >= 16)
		count += ft_hexa_max(num / 16);
	i = (num % 16);
	count += write(1, &base[i], 1);
	return (count);
}
