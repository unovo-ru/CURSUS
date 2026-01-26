/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:28:01 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/08/04 21:14:18 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexa_min(unsigned long long num)
{
	int			i;
	char		*base;
	int			count;

	count = 0;
	base = "0123456789abcdef";
	if (num >= 16)
		count = count + ft_hexa_min(num / 16);
	i = (num % 16);
	count += pf_putchar_fd(base[i]);
	return (count);
}
