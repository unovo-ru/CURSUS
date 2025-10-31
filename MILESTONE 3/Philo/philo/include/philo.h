/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:16:08 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/28 19:51:20 by unovo-ru         ###   ########.fr       */
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

# define PHILO_MAX 200
# define ERR_ARGS	"Error: Invalid number of arguments\n"
# define ERR_MALLOC	"Error: Memory allocation failed\n"
# define ERR_MUTEX	"Error: Mutex initialization failed\n"
# define ERR_INPUT	"Error: Invalid input\n"

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"

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

/* --------------------------------- Parse ---------------------------------- */
int			parse_arg(int ac, char **av);

/* --------------------------------- Utils ---------------------------------- */
int			ft_atoi(char *nptr);
int			ft_isdigit_space(int c);
int			is_space(char c);

/* ---------------------------- Initialization ------------------------------ */
int			init_status(int ac, char **av, t_status *status);
int			init_mutex(t_status *status);
int			init_philos(t_status *status);

/* --------------------------------- Time ----------------------------------- */
long long	get_time(void);
void		ft_usleep(long long time_ms, t_philo *philo);

/* ------------------------------- Routines --------------------------------- */
int			print_status(t_philo *philo, char *status_msg, int force_print);
int			check_death(t_philo *philo);
void		*one_philo(t_philo *philo);
void		*philo_routine(void *arg);
void		set_sim_stop(t_status *status, int val);
void		*routine(void *arg);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);
int			is_all_ate_enough(t_status *status);



/* -------------------------------- Threads --------------------------------- */
void		create_threads(t_status *status);
void		wait_threads(t_status *status);
void		*big_brother(void *arg);

/* -------------------------------- Cleanup --------------------------------- */
void		free_the_chain(t_status *status);
void		msg_error(t_status *status);

#endif