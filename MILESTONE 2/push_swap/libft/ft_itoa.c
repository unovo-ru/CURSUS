/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:56:47 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/05/14 11:02:40 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numsize(int n)
{
	long int	m;
	int			count;

	count = 1;
	m = n;
	if (n < 0)
	{
		count++;
		m = -m;
	}
	while (m / 10 >= 1)
	{
		m = m / 10;
		count++;
	}
	return (count);
}

static int	divnum(int n)
{
	long int	m;
	int			div;

	m = n;
	div = 1;
	if (m < 0)
		m = -m;
	while (m / 10 >= 1)
	{
		div = div * 10;
		m = m / 10;
	}
	return (div);
}

static char	*res_memory(int n)
{
	long int	num;
	char		*s;

	num = n;
	s = (char *)ft_calloc((numsize(num) + 1), sizeof(char));
	return (s);
}

char	*ft_itoa(int n)
{
	long int	m;
	char		*num;
	int			i;
	int			size_n ;
	int			div;

	i = 0;
	m = n;
	if (m < 0)
		m = -m;
	size_n = numsize(n);
	div = divnum(n);
	num = res_memory(n);
	if (!num)
		return (NULL);
	while (i < size_n)
	{
		if (n < 0 && i == 0)
			num[i++] = '-';
		num[i] = (m / div) + '0';
		m = m % div;
		div = div / 10;
		i++;
	}
	return (num);
}
