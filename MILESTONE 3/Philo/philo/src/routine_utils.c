/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:15:14 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/28 19:39:27 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	print_status(t_philo *philo, char *status, int force_print)
{
	long long	time;
	int			died;

	pthread_mutex_lock(&philo->status->death_mutex);
	died = philo->status->someone_died;
	pthread_mutex_unlock(&philo->status->death_mutex);
	if (died && !force_print)
		return (1);
	pthread_mutex_lock(&philo->status->print_mutex);
	time = get_time() - philo->status->start_time;
	printf("%lld %d %s\n", time, philo->id, status);
	pthread_mutex_unlock(&philo->status->print_mutex);
	return (0);
}

int	check_death(t_philo *philo)
{
	long long	t_since_meal;
	int			is_eating;

	pthread_mutex_lock(&philo->status->meal_mutex);
	t_since_meal = get_time() - philo->last_meal_time;
	is_eating = philo->is_eating;
	pthread_mutex_unlock(&philo->status->meal_mutex);
	if (t_since_meal >= philo->status->time_to_die && !is_eating)
	{
		set_sim_stop(philo->status, 1);
		print_status(philo, "died", 1);
		return (1);
	}
	return (0);
}

void	ft_usleep(long long time_ms, t_philo *philo)
{
	long long	start;

	start = get_time();
	while (get_time() - start < time_ms)
	{
		pthread_mutex_lock(&philo->status->death_mutex);
		if (philo->status->someone_died)
		{
			pthread_mutex_unlock(&philo->status->death_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->status->death_mutex);
		usleep(100);
	}
}
