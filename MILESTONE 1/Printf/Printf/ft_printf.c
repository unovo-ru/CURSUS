/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:56:44 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/05/28 11:32:27 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *input, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, input);
	i = 0;
	count = 0;
	while (input[i] != '\0')
	{
		if ((input[i] == '%') && (input[i + 1]))
			count = count + ft_var_type(args, input[++i]);
		else
			count = count + ft_putchar_fd(input[i]);
		i++;
	}
	va_end(args);
	return (count);
}
// int main(void)
// {
// 	ft_printf("hola que tal\n");
// 	printf("hola que tal\n");
// 	return (0);
// }
