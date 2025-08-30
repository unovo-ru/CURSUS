/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:51:11 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/09 18:16:48 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
int is_power_of_2(int nbr)
{
	int n = 1; 
	while (n <= nbr)
	{
		if (n == nbr)
			return (1);
		n *= 2;
	}
	return (0);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = atoi(av[1]);
		printf("%d", is_power_of_2(i));
	}
	return (0);
}
