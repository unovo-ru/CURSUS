/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:02:43 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/13 16:09:35 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
los argumentos deben ser o 5 o 6, ni mas ni menos
deben ser solo numeros
no deben tomar valores negativos
*/

int	parse_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac < 5 || ac > 6)
		return (0);
	while (av[++i])
	{
		if (!ft_atoi(av[i]) || ft_atoi(av[i]) == -1)
			return (0);
		else if (av[i] == NULL)
			return (0);
	}
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
			if (!ft_isdigit(av[i][j++]))
				return (0);
		i++;
	}
	return (1);
}
