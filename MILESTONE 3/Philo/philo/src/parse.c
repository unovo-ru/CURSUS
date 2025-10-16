/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:02:43 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/16 11:50:10 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
los argumentos deben ser o 5 o 6, ni mas ni menos
deben ser solo numeros
no deben tomar valores negativos
*/

void	print_error(int error_code)
{
	if (error_code == -1)
		printf(ERROR_ARGS);
	if (error_code == -2)
		printf(ERROR_INPUT);
	if (error_code == -3)
		printf(ERROR_MALLOC);
	if (error_code == -4)
		printf(ERROR_THREAD);
	if (error_code == -5)
		printf(ERROR_MUTEX);
}

int	parse_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac < 5 || ac > 6)
		return (-1);
	while (av[++i])
	{
		if (!ft_atoi(av[i]) || ft_atoi(av[i]) == -1)
			return (-2);
		else if (av[i] == NULL)
			return (-2);
	}
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
			if (!ft_isdigit_space(av[i][j++]))
				return (-2);
		i++;
	}
	return (1);
}
