/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:44:04 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/05/12 20:39:08 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	sig(int n)
{
	int			s_count;
	long int	m;

	m = n;
	s_count = 0;
	if (m < 0)
	{
		s_count++;
		m = -m;
	}
	while (m >= 10)
	{
		s_count++;
		m = m / 10;
	}
	if (m < 10)
	{
		s_count++;
		m = m % 10;
	}
	return (s_count);
}

char	*ft_itoa(int n)
{
	char		*myarray;
	int			space;
	long int	m;

	m = n;
	space = sig(m);
	myarray = (char *)malloc(sizeof(char) * (space + 1));
	if (!myarray)
		return (NULL);
	if ((m < 0) && (sig > 0))
	{
		myarray[0] = '-';
		m = -m;
	}
	if (m == 0)
		myarray[0] = '0';
	myarray[space] = '\0';
	while (m && space > 0)
	{
		myarray[space - 1] = (m % 10) + '0';
		space--;
		m = m / 10;
	}
	return (myarray);
}
int	main(void)
{
	char	*myarray;

	myarray = ft_itoa(747383700);
	printf("%s", myarray);
	free(myarray);
	return (0);
}
