/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens_mio.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:38:47 by jbrosio           #+#    #+#             */
/*   Updated: 2025/11/06 10:46:20 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

void ft_putnbr(int num)
{
	if (num > 9)
	{
		ft_putnbr(num / 10);
		char n = num % 10 + '0';
		write(1, &n, 1);
		return ;
	}
	else
	{
		char number = num + '0';
		write(1, &number, 1);
		return ;
	}
}

int is_valid_pos(int *table, int x, int y)
{
	for (int i = 0; i < y; i++)
	{
		if (x == table[i])
			return (0);
		if ((x - y) == (table[i] - i))
			return (0);
		if ((x + y) == (table[i] + i))
			return (0);
	}
	return (1);
}

void print_table(int *table, int size)
{
	int i = 0;

	while (i < size)
	{
		ft_putnbr(table[i]);
		i++;
	}
	write(1, "\n", 1);
}

void n_queen(int *table, int y, int x, int size)
{
	if (y == size)
	{
		print_table(table, size);
		return ;
	}
	while(x < size)
	{
		if (is_valid_pos(table, x, y))
		{
			table[y] = x;
			n_queen(table, y + 1, 0, size);
		}
		x++;
	}
	return ;
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (write(1, "\n", 1), 0);
	int size = atoi(av[1]);
	int table[size];
	n_queen(table, 0, 0, size);
	return (0);
}
