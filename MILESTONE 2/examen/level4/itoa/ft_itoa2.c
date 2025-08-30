/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:21:55 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/28 20:28:44 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr)
{
	int n = nbr;
	char *number;
	int count = 0;
	if (n < 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	number = malloc(count * sizeof(char) + 1);
	number[count] = '\0';
	if (nbr < 0)
	{
		number[0] = '-';
		nbr = -nbr;
	}
	count--;
	while (nbr)
	{
		number[count] = nbr % 10 + '0';
		nbr /= 10;
		count--;
	}
	return (number);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("%s", ft_itoa(atoi(av[1])));
	}
	printf("\n");
	return 0;
}
