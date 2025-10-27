/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:03:46 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/27 16:33:21 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_status *status)
{
	int	i;

	i = 0;
	while (i > status->num_philos)
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

	pthread_mutex_lock(&philo->status->meal_mutex);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->status->meal_mutex);
	if (philo->id % 2 == 0)
		ft_usleep(philo->status->time_to_eat / 2, philo);
	
}