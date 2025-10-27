/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:16:08 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/27 16:13:14 by unovo-ru         ###   ########.fr       */
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

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"

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
	int					is_eating;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	struct s_status		*status;
}			t_philo;

typedef struct s_status
{
	int					mutex_count;
	int					forks_setted;

	// int					code_err_count;
	int					num_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat_count;
	int					has_num_must_eat;
	int					someone_died;		// proteger con mutex
	int					all_ate;			// proteger con mutex
	long long			start_time;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		meal_mutex;
	pthread_mutex_t		death_mutex;
	t_philo				*philos;
}			t_status;

/* ========================================================================== */
/*                                 FUNCTIONS                                  */
/* ========================================================================== */

int		parse_arg(int ac, char **av);
int		ft_atoi(const char *nptr);
int		ft_isdigit_space(int c);
int		is_space(char c);

int		init_status(int ac, char **av, t_status *status);
int		init_mutex(t_status *status);
int		init_philos(t_status *status);

#endif