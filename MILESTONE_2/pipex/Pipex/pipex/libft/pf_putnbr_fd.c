/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:24:35 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/08/04 20:58:20 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_putnbr_fd(int n)
{
	long int	num;
	char		c;
	int			count;

	num = n;
	count = 0;
	if (num < 0)
	{
		num = -num;
		count++;
		write (1, "-", 1);
	}
	if (num >= 10)
		count += pf_putnbr_fd(num / 10);
	c = (num % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}
