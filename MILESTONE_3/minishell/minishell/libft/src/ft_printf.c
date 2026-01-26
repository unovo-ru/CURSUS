/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:14:36 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/23 14:14:37 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf(char const *s, ...)
{
	va_list			vargs;
	unsigned int	i;
	unsigned int	printed;

	printed = 0;
	va_start(vargs, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			printed += ft_searchtype(vargs, s[i + 1]);
			i += 2;
		}
		else
		{
			printed += ft_putchar_fd(s[i], 1);
			i++;
		}
	}
	va_end(vargs);
	return (printed);
}
