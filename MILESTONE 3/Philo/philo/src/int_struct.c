/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:21:47 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/31 14:00:25 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_status(int ac, char **av, t_status *status)
{
	status->num_philos = ft_atoi(av[1]);
	status->time_to_die = ft_atoi(av[2]);
	status->time_to_eat = ft_atoi(av[3]);
	status->time_to_sleep = ft_atoi(av[4]);
	status->must_eat_count = -1;
	status->has_num_must_eat = 0;
	if (ac == 6)
	{
		status->must_eat_count = ft_atoi(av[5]);
		status->has_num_must_eat = 1;
	}
	status->someone_died = 0;
	status->all_ate = 0;
	status->start_time = 0;
	status->mutex_count = 0;
	status->forks_setted = 0;
	status->philos = malloc(sizeof(t_philo) * status->num_philos);
	if (!status->philos)
		return (1);
	return (0);
}

static void	destroy_mutex(t_status *status)
{
	int	i;

	i = 0;
	if (status->mutex_count >= 4)
		pthread_mutex_destroy(&status->death_mutex);
	if (status->mutex_count >= 3)
		pthread_mutex_destroy(&status->meal_mutex);
	if (status->mutex_count >= 2)
		pthread_mutex_destroy(&status->print_mutex);
	if (status->mutex_count >= 1)
	{
		while (i < status->forks_setted)
		{
			pthread_mutex_destroy(&status->forks[i]);
			i++;
		}
	}
	if (status->forks)
		free(status->forks);
	if (status->philos)
		free(status->philos);
}

static int	init_mutex_aux(t_status *status)
{
	if (pthread_mutex_init(&status->print_mutex, NULL) != 0)
	{
		status->mutex_count = 2;
		destroy_mutex(status);
		return (1);
	}
	if (pthread_mutex_init(&status->meal_mutex, NULL) != 0)
	{
		status->mutex_count = 3;
		destroy_mutex(status);
		return (1);
	}
	if (pthread_mutex_init(&status->death_mutex, NULL) != 0)
	{
		status->mutex_count = 4;
		destroy_mutex(status);
		return (1);
	}
	return (0);
}

int	init_mutex(t_status *status)
{
	int	i;

	i = 0;
	status->forks = malloc(sizeof(pthread_mutex_t) * status->num_philos);
	if (!status->forks)
	{
		free(status->philos);
		return (1);
	}
	while (i < status->num_philos)
	{
		if (pthread_mutex_init(&status->forks[i], NULL) != 0)
		{
			status->mutex_count = 1;
			status->forks_setted = i;
			destroy_mutex(status);
			return (1);
		}
		i++;
	}
	status->forks_setted = status->num_philos;
	if (init_mutex_aux(status))
		return (1);
	return (0);
}

int	init_philos(t_status *status)
{
	int	i;

	if (init_mutex(status) != 0)
	{
		msg_error(status);
		return (1);
	}
	i = 0;
	while (i < status->num_philos)
	{
		status->philos[i].id = i + 1;
		status->philos[i].meals_eaten = 0;
		status->philos[i].last_meal_time = 0;
		status->philos[i].is_eating = 0;
		status->philos[i].status = status;
		status->philos[i].left_fork = &status->forks[i];
		status->philos[i].right_fork
			= &status->forks[(i + 1) % status->num_philos];
		i++;
	}
	return (0);
}
