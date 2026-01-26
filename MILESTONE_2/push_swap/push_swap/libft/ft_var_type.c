/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 19:24:44 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/08/04 21:14:18 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_var_type(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = count + pf_putchar_fd(va_arg(args, int));
	else if (c == 's')
		count = count + pf_putstr_fd(va_arg(args, char *));
	else if (c == 'p')
		count = count + ft_hexa(va_arg(args, void *));
	else if (c == 'd')
		count = count + pf_putnbr_fd(va_arg(args, int));
	else if (c == 'i')
		count = count + pf_putnbr_fd(va_arg(args, int));
	else if (c == 'u')
		count = count + ft_put_unsig(va_arg(args, unsigned int));
	else if (c == 'x')
		count = count + ft_hexa_min(va_arg(args, unsigned int));
	else if (c == 'X')
		count = count + ft_hexa_max(va_arg(args, unsigned int));
	else if (c == '%')
		count = count + pf_putchar_fd('%');
	return (count);
}
