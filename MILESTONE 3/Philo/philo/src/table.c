/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:08:49 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/27 20:08:05 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork", 0);
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork", 0);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork", 0);
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork", 0);
	}
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_eat(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->status->meal_mutex);
	philo->is_eating = 1;
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->status->meal_mutex);
	print_status(philo, "is eating", 0);
	ft_usleep(philo->status->time_to_eat, philo);
	pthread_mutex_lock(&philo->status->meal_mutex);
	philo->meals_eaten++;
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->status->meal_mutex);
	drop_forks(philo);
}

void	philo_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping", 0);
	ft_usleep(philo->status->time_to_sleep, philo);
}

void	philo_think(t_philo *philo)
{
	print_status(philo, "is thinking", 0);
}
