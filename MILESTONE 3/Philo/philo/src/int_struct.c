/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:21:47 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/16 13:16:56 by unovo-ru         ###   ########.fr       */
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
	status->someone_died = 0;
	status->all_ate = 0;
	status->start_time = 0;
	status->philos = malloc(sizeof(t_philo) * status->num_philos);
	if (!status->philos)
		return ;
	status->forks = malloc(sizeof(pthread_mutex_t) * status->num_philos);
	if (!status->forks)
	{
		free(status->philos);
		return ;
	}
}

void	init_philos(t_status *status)
{
	int	i;

	i = 0;
	while (i < status->num_philos)
	{
		status->philos[i].id = i + 1;
		status->philos[i].meals_eaten = 0;
		status->philos[i].last_meal_time = 0;
		status->philos[i].status = 0;
	}
}
