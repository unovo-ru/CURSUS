/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_control_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:14:36 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/23 14:14:37 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	puthex_p_fd(unsigned long long num, int fd)
{
	char	*digits;
	int		printed;

	printed = 0;
	if (!num)
	{
		printed += ft_putstr_fd("(nil)", fd);
		return (printed);
	}
	printed += ft_putstr_fd("0x", fd);
	digits = "0123456789abcdef";
	if (num < 16)
		printed += ft_putchar_fd(digits[num], fd);
	if (num >= 16)
	{
		printed += puthex_lower_fd(num / 16, fd);
		printed += ft_putchar_fd(digits[num % 16], fd);
	}
	return (printed);
}

int	puthex_lower_fd(unsigned long long num, int fd)
{
	char	*digits;
	int		printed;

	printed = 0;
	digits = "0123456789abcdef";
	if (num < 16)
		printed += ft_putchar_fd(digits[num], fd);
	else if (num >= 16)
	{
		printed += puthex_lower_fd(num / 16, fd);
		printed += ft_putchar_fd(digits[num % 16], fd);
	}
	return (printed);
}

int	puthex_upper_fd(unsigned long long num, int fd)
{
	char	*digits;
	int		printed;

	printed = 0;
	digits = "0123456789ABCDEF";
	if (num < 16)
		printed += ft_putchar_fd(digits[num], fd);
	else if (num >= 16)
	{
		printed += puthex_upper_fd(num / 16, fd);
		printed += ft_putchar_fd(digits[num % 16], fd);
	}
	return (printed);
}
