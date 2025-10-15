/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:21:47 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/15 15:48:24 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_status(int ac, char **av, t_status *status)
{
	status->num_philos = ft_atoi(av[1]);
	status->time_to_die = ft_atoi(av[2]);
	status->time_to_eat = ft_atoi(av[3]);
	status->time_to_sleep = ft_atoi(av[4]);
	status->must_eat_count = -1;
	if (ac == 6)
		status->must_eat_count = ft_atoi(av[5]);
}

void	init_philos(int ac, char **av, t_philo *philos)
{
	philos->id = 
	philos->meals_eaten = 0;
	philos->last_meal_time = /*inicia con el tiempo de la simulacion*/
	philos->thread = 
	philos->*left_fork
	philos->*right_fork
	philos->*status
}