/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:40:27 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/05/21 20:58:49 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa(void *y)
{
	int			count;

	count = 0;
	if (!y)
	{
		ft_putstr_fd("(nil)");
		return (5);
	}
	count += ft_putchar_fd('0');
	count += ft_putchar_fd('x');
	count += ft_hexa_min((unsigned long long)y);
	return (count);
}
