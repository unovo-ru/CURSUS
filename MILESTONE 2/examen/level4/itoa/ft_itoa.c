/ ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:49:02 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/28 19:21:34 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char *ft_itoa(int nbr)
{
	int len = 0;
	long n = nbr;
	char *myarray = NULL;
	if (nbr < 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	myarray = (char *)malloc((len + 1) * sizeof(char));
	if (!myarray)
		return (NULL);
	
	myarray[len] = '\0';
	n = nbr;
	if (n < 0)
	{
		n = -n;
		myarray[0] = '-';
	}
	int i = len - 1;
	while (n >= 10)
	{
		myarray[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	if (n < 10)
		myarray[i] = n + '0';
	return (myarray);
}

int main(void)
{
	int nb = -2147483648;
	printf("%s", ft_itoa(nb));
	return (0);
}
