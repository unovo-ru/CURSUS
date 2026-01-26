/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_searchtype.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:14:36 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/23 14:14:37 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_searchtype(va_list vargs, char c)
{
	unsigned int	printed;

	printed = 0;
	if (c == 'c')
		printed += ft_putchar_fd(va_arg(vargs, int), 1);
	else if (c == 's')
		printed += ft_putstr_fd(va_arg(vargs, char *), 1);
	else if (c == 'd' || c == 'i')
		printed += ft_putnbr_fd(va_arg(vargs, int), 1);
	else if (c == 'u')
		printed += ft_putnbr_u(va_arg(vargs, unsigned int));
	else if (c == '%')
		printed += ft_putchar_fd('%', 1);
	else if (c == 'p')
		printed += ft_puthex_p((unsigned long long)va_arg(vargs,
					unsigned long long));
	else if (c == 'x')
		printed += ft_puthex_x((unsigned int)va_arg(vargs, unsigned int));
	else if (c == 'X')
		printed += ft_puthex_mayus((unsigned int)va_arg(vargs, unsigned int));
	return (printed);
}
