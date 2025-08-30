/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:41:59 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/21 16:47:05 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void fprime(int nbr)
{
	int i = 2;
	if (nbr == 1)
		printf("1");
	while (nbr > 1)
	{
		if (nbr % i == 0)
		{
			printf("%d", i);
			nbr /= i;
			if (i <= nbr)
				printf("*");
		}
		else
			i++;
	}
}

int main (int ac, char **av)
{
	if (ac == 2)
		fprime(atoi(av[1]));
	printf("\n");
	return (0);

}
