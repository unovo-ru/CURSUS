/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:57:49 by jbrosio           #+#    #+#             */
/*   Updated: 2025/11/06 11:56:02 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

int ft_strlen(char *s)
{
	int i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

void bubble_sort(char *av)
{
	int i = 0, j;
	char aux;

	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (av[i] > av[j])
			{
				aux = av[i];
				av[i] = av[j];
				av[j] = aux;
			}
			j++;
		}
		i++;
	}
}

void	find_combination(char *av, char *aux, int *used, int i, int j, int size)
{
	if (j == size)
	{
		puts(aux);
		return ;
	}
	while (i < size)
	{
		if (!used[i])
		{
			used[i] = 1;
			aux[j] = av[i];
			find_combination(av, aux, used, 0, j + 1, size);
			used[i] = 0;
		}
		i++;
	}
}

int	permutation(char *av, char *aux, int size)
{
	int i = 0;
	int *used;
	used = calloc(size, sizeof(int));
	if (!used)
	{
		free(aux);
		return (1);
	}
	while (i < size)
	{
		used[i] = 1;
		aux[0] = av[i];
		find_combination(av, aux, used, 0, 1, size);
		used[i] = 0;
		i++;
	}
	free(used);
	return (0);
}

int main(int ac, char **av)
{
	int size = ft_strlen(av[1]);
	char *aux;

	if (ac != 2)
		return (1);
	bubble_sort(av[1]);
	aux = malloc(size + 1 * sizeof(char));
	if (!aux)
		return (1);
	aux[size + 1] = '\0';
	if (permutation(av[1], aux, ft_strlen(av[1])))
		return (1);
	free(aux);
	return (0);
}
