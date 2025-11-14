/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrosio <jbrosio@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:18:56 by jbrosio           #+#    #+#             */
/*   Updated: 2025/11/06 14:30:26 by jbrosio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdio.h"

int	ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int	get_rest(char *av)
{
	int i = 0, open = 0, extra_close = 0;
	while (av[i])
	{
		if (av[i] == '(')
			open++;
		else if (av[i] == ')')
		{
			if (open > 0)
				open--;
			else
				extra_close++;
		}
		i++;
	}
	return (open + extra_close);
}

int	get_open_close(char *av, int *left, int *right)
{
	int i = 0;
	while (av[i])
	{
		if (av[i] == '(')
			(*left)++;
		else if (av[i] == ')')
		{
			if (*left > 0)
				(*left)--;
			else
				(*right)++;
		}
		i++;
	}
	return (*left + *right);
}

/** 
 * 
 * [ argument ] = argumento recibido por parametro
 * [ aux ] = copia del argumento recibido
 * [ index ] = iterador de los dos arrays
 * [ right ] = contador de ")"
 * [ left ] = contador de "("
 * [ size ] = tamaño del argumento
 * 
*/
void	rip(char *argument, char *aux, int index, int right, int left, int size)
{
	if (index == size)
	{
		if (!right && !left && !get_rest(aux))
		{
			puts(aux);
			return ;
		}
		return ;
	}
	if (aux[index] == '(' && left > 0)
	{
		aux[index] = ' ';
		rip(argument, aux, index + 1, right, left - 1, size);
	}
	if (aux[index] == ')' && right > 0)
	{
		aux[index] = ' ';
		rip(argument, aux, index + 1, right - 1, left, size);
	}
	aux[index] = argument[index];
	rip(argument, aux, index + 1, right, left, size);
}

int main(int ac, char **av)
{
	int i = 0;
	char aux[1000];
	if (ac < 2)
		return (0);

	while (av[1][i])
	{
		aux[i] = av[1][i];
		i++;
	}
	aux[i] = '\0';
	int l = 0, r = 0;
	get_open_close(av[1], &l, &r);
	rip(av[1], aux, 0, r, l, ft_strlen(av[1]));
	return (0);
}
