/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_brother.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:57:40 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/27 19:11:26 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_sim_stop(t_status *status, int val)
{
	pthread_mutex_lock(&status->death_mutex);
	status->someone_died = val;
	pthread_mutex_unlock(&status->death_mutex);
}

void	*big_brother(void *arg)
{
	t_status	*status;
	int			i;

	status = (t_status *)arg;
	while (1)
	{
		i = 0;
		while (i < status->num_philos)
		{
			if (check_death(&status->philos[i]))
				return (NULL);
			i++;
		}
		if (is_all_ate_enough(status))
		{
			set_sim_stop(status, 1);
			return (NULL);
		}
		usleep(1000);
	}
}

int	is_all_ate_enough(t_status *status)
{
	int	i;
	int	count_finished;

	if (status->must_eat_count == -1)
		return (0);
	i = 0;
	count_finished = 0;
	pthread_mutex_lock(&status->meal_mutex);
	while (i < status->num_philos)
	{
		if (status->philos[i].meals_eaten >= status->must_eat_count)
			count_finished++;
		i++;
	}
	pthread_mutex_unlock(&status->meal_mutex);
	return (count_finished == status->num_philos);
}