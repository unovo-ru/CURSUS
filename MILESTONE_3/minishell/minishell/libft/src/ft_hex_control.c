/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:14:36 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/23 14:14:37 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_puthex_p(unsigned long long num)
{
	char	*digits;
	int		printed;

	printed = 0;
	if (!num)
	{
		printed += ft_putstr_fd("(nil)", 1);
		return (printed);
	}
	printed += ft_putstr_fd("0x", 1);
	digits = "0123456789abcdef";
	if (num < 16)
		printed += ft_putchar_fd(digits[num], 1);
	if (num >= 16)
	{
		printed += ft_puthex_x(num / 16);
		printed += ft_putchar_fd(digits[num % 16], 1);
	}
	return (printed);
}

int	ft_puthex_x(unsigned long long num)
{
	char	*digits;
	int		printed;

	printed = 0;
	digits = "0123456789abcdef";
	if (num < 16)
		printed += ft_putchar_fd(digits[num], 1);
	else if (num >= 16)
	{
		printed += ft_puthex_x(num / 16);
		printed += ft_putchar_fd(digits[num % 16], 1);
	}
	return (printed);
}

int	ft_puthex_mayus(unsigned long long num)
{
	char	*digits;
	int		printed;

	printed = 0;
	digits = "0123456789ABCDEF";
	if (num < 16)
		printed += ft_putchar_fd(digits[num], 1);
	else if (num >= 16)
	{
		printed += ft_puthex_mayus(num / 16);
		printed += ft_putchar_fd(digits[num % 16], 1);
	}
	return (printed);
}
