/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:40:27 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/08/04 21:14:18 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexa(void *y)
{
	int			count;

	count = 0;
	if (!y)
	{
		pf_putstr_fd("(nil)");
		return (5);
	}
	count += pf_putchar_fd('0');
	count += pf_putchar_fd('x');
	count += ft_hexa_min((unsigned long long)y);
	return (count);
}
