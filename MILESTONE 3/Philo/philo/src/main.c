/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:07:59 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/27 18:00:32 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo(t_philo *philo)
{
	print_status(philo, "has taken a fork", 0);
	ft_usleep(philo->status->time_to_die, philo);
	return (NULL);
}

void	philos_at_table(t_status *status, int ac, char **av)
{
	int			i;
	pthread_t	b_brother;

	init_status(ac, av, status);
	init_philos(status);
	status->start_time = get_time();
	i = 0;
	while (i < status->num_philos)
	{
		status->philos[i].last_meal_time = status->start_time;
		i++;
	}
	create_threads(status);
	pthread_create(&b_brother, NULL, big_brother, status);
	wait_threads(status);
	pthread_join(b_brother, NULL);
}

int	main(int ac, char **av)
{
	t_status	status;

	if (parse_arg(ac, av))
	{
		printf(ERR_ARGS);
		return (1);
	}
	philos_at_table(&status, ac, av);
	free_the_chain(&status);
	return (0);
}
