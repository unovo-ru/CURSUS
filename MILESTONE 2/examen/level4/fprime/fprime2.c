/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:56:15 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/21 16:53:59 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int x = atoi(av[1]);
		int div = 2;
		if (x == 1)
			printf("1");
		while (x > 1)
		{
			if (x % div == 0)
			{
				printf("%d", div);
				x = x /div;
				if (div <= x)
					printf("*");
			}
			else
				div++;
		}
	}
	printf("\n");
	return (0);
}
