/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:03:46 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/27 20:05:54 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_status *status)
{
	int	i;

	i = 0;
	while (i < status->num_philos)
	{
		if (pthread_create(&status->philos[i].thread, NULL, routine,
				&status->philos[i]) != 0)
		{
			msg_error(status);
			return ;
		}
		i++;
	}
}

void	wait_threads(t_status *status)
{
	int	i;

	i = 0;
	while (i < status->num_philos)
	{
		pthread_join(status->philos[i].thread, NULL);
		i++;
	}
}

int	should_stop(t_philo *philo)
{
	int	stop;

	pthread_mutex_lock(&philo->status->death_mutex);
	stop = philo->status->someone_died;
	pthread_mutex_unlock(&philo->status->death_mutex);
	return (stop);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	// pthread_mutex_lock(&philo->status->death_mutex);
	if (philo->id % 2 == 0)
		ft_usleep(philo->status->time_to_eat / 2, philo);
	if (philo->status->num_philos > 3)
		ft_usleep((philo->id % 3) * 10, philo);
	while (1)
	{
		if (should_stop(philo))
			break ;
		philo_think(philo);
		if (should_stop(philo))
			break ;
		philo_eat(philo);
		if (should_stop(philo))
			break ;
		philo_sleep(philo);
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->status->num_philos == 1)
		return (one_philo(philo));
	if (philo->id % 2 == 0)
		usleep(1000);
	return (philo_routine(philo));
}