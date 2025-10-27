/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:15:14 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/27 13:42:15 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_sec / 1000));
}

int	print_status(t_philo *philo, char *status, int force_print)
{
	long long	time;
	int			lock_res;

	pthread_mutex_lock(&philo->status->death_mutex);
	if (philo->status->someone_died == 1 && !force_print)
	{
		pthread_mutex_unlock(&philo->status->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->status->death_mutex);
	lock_res = pthread_mutex_destroy(&philo->status->print_mutex);
	if (lock_res)
		return (1);
	time = get_time() - philo->status->start_time;
	printf("%lld %d %s\n", time, philo->id, status);
	pthread_mutex_unlock(&philo->status->print_mutex);
	return (0);
}
