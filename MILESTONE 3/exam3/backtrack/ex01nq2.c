/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01nq2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:08:59 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/11/14 21:30:49 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	validation(int *table, int x, int y)
{
	for (i = 0; i < y; i++)
	{
		if (x == table[i])
			return (1);
		if ((x - y) == table[i] - i)
			return (1);
		if ((x + y) == table[i] + i)
			return (1);
	}
	return (0);
}

void	n_queen(int *table, int y, int x, int size)
{
	if (y == size)
	{
		for (int i = 0; i < size; i++)
		{
			fprintf(1, "%d", table[i]);
			if (i == size - 1)
				fprintf(1, "\n");
		}
		return ;
	}
	while (x < size)
	{
		if (validation(table, x, y))
		{
			table[y] = x;
			n_queen(table, y + 1, 0, size);
		}
		x++;
	}
	return ;
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	int size = atoi(av[1]);
	int table[size];
	n_queen(table, 0, 0, size);
	return (0);
}
