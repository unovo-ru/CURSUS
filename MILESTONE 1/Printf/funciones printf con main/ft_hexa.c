/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:40:27 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/05/20 19:16:46 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
//#include "libft.h"

int	ft_hexa(void *y)
{
	long int	num;

	num = (long int)y;
	ft_putchar_fd('0');
	ft_putchar_fd('x');
	ft_putchar_fd(ft_hexa_min(num));
	return (num);
}

int	main(void)
{
	void	*x;

	ft_hexa(x);
	write (1, "\n", 1);
	printf("%p", x);
	return (0);
}
