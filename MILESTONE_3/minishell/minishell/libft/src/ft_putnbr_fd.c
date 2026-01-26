/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:14:36 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/23 14:14:37 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long int	num;
	int			printed;

	printed = 0;
	num = n;
	if (num < 0)
	{
		printed += ft_putchar_fd('-', 1);
		num = -num;
	}
	if (num >= 10)
	{
		printed += ft_putnbr_fd(num / 10, fd);
		num %= 10;
	}
	if (num < 10)
	{
		num += '0';
		printed += write(fd, &num, 1);
	}
	return (printed);
}
