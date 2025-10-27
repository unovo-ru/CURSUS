/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:08:36 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/27 19:13:27 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error(void)
{
	printf("usage: ");
	printf("./philo n_philos t_die t_eat t_sleep [num_meals_to_eat]\n");
}

void	destroy_mutex(t_status *status)
{
	int	i;

	i = 0;
	if (status->forks && status->mutex_count >= 1)
	{
		while (i < status->forks_setted)
		{
			pthread_mutex_destroy(&status->forks[i]);
			i++;
		}
	}
	if (status->mutex_count >= 2)
		pthread_mutex_destroy(&status->print_mutex);
	if (status->mutex_count >= 3)
		pthread_mutex_destroy(&status->meal_mutex);
	if (status->mutex_count >= 4)
		pthread_mutex_destroy(&status->death_mutex);
}

void	free_the_chain(t_status *status)
{
	destroy_mutex(status);
	if (status->forks)
	{
		free(status->forks);
		status->forks = NULL;
	}
	if (status->philos)
	{
		free(status->philos);
		status->philos = NULL;
	}
}

void	msg_error(t_status *status)
{
	free_the_chain(status);
	printf("error\n");
}
