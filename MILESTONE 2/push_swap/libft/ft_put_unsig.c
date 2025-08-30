/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:33:10 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/08/04 21:14:18 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_unsig(unsigned int n)
{
	unsigned long	num;
	char			c;
	int				count;

	num = n;
	count = 0;
	if (num >= 10)
		count += pf_putnbr_fd(num / 10);
	c = (num % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}
