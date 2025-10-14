/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:16:08 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/14 17:02:24 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>

/* ========================================================================== */
/*                                   MACROS                                   */
/* ========================================================================== */

# define ERROR_ARGS		"Error: Invalid number of arguments\n"	// -1
# define ERROR_INPUT	"Error: Invalid input\n"				// -2
# define ERROR_MALLOC	"Error: Memory allocation failed\n"		// -3
# define ERROR_THREAD	"Error: Thread creation failed\n"		// -4
# define ERROR_MUTEX	"Error: Mutex initialization failed\n"	// -5

# define MSG_FORK		"has taken a fork"
# define MSG_EAT		"is eating"
# define MSG_SLEEP		"is sleeping"
# define MSG_THINK		"is thinking"
# define MSG_DIED		"died"

/* ========================================================================== */
/*                                  STRUCTS                                   */
/* ========================================================================== */

typedef struct s_philo
{
	int					id;
	int					meals_eaten;
	long long			last_meal_time;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	struct s_status		*data;
}			t_philo;

typedef struct s_status
{
	int					num_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat_count;
	int					someone_died;		// proteger con mutex
	int					all_ate;			// proteger con mutex
	long long			start_time;
	t_philo				*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
	pthread_mutex_t		meal_check;
}			t_status;

/* ========================================================================== */
/*                                 FUNCTIONS                                  */
/* ========================================================================== */

int		parse_arg(int ac, char **av);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
void	print_error(int error_code);
int	is_space(char c);

#endif