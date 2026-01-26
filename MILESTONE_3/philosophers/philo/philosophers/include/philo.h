/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:16:08 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/23 18:06:05 by unovo-ru         ###   ########.fr       */
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

/**
 * @brief Structure representing a single philosopher.
 */
typedef struct s_philo
{
	int				id;				/* Philosopher ID (1 to num_philos) */
	int				meals_eaten;	/* Count of meals consumed */
	long long		last_meal_time;	/* Times of the last meal start */
	int				is_eating;		/* Status flag: 1 if eating */
	pthread_t		thread;			/* POSIX thread ID */
	pthread_mutex_t	*left_fork;		/* Pointer to left fork mutex */
	pthread_mutex_t	*right_fork;	/* Pointer to right fork mutex */
	struct s_status	*status;		/* Reference to main simulation data */
}	t_philo;

/**
 * @brief Main simulation structure containing shared data and configuration.
 */
typedef struct s_status
{
	int					mutex_count;	/* Tracks init'd mutexes for cleanup */
	int					forks_setted;	/* Tracks init'd forks for cleanup */
	int					num_philos;		/* Total number of philosophers */
	int					time_to_die;	/* Max time without eating in ms */
	int					time_to_eat;	/* Time required to eat in ms */
	int					time_to_sleep;	/* Time required to sleep in ms */
	int					must_eat_count;	/* Min meals per philo (-1 if none) */
	int					someone_died;	/* Flag: 1 if simulation must end */
	int					all_ate;		/* Flag: 1 if all finished meals */
	long long			start_time;		/* Start timestamp of simulation */
	pthread_mutex_t		*forks;			/* Array of fork mutexes */
	pthread_mutex_t		print_mutex;	/* Mutex for thread-safe printing */
	pthread_mutex_t		meal_mutex;		/* Mutex for food/meal protection */
	pthread_mutex_t		death_mutex;	/* Mutex for sim status checks */
	t_philo				*philos;		/* Array of philosopher structures */
}	t_status;

/* ========================================================================== */
/*                                 FUNCTIONS                                  */
/* ========================================================================== */

/* ========================================================================== */
/*                                  Parsing                                   */
/* ========================================================================== */

/**
 * @brief Parses and validates command line arguments.
 * @param ac The argument count.
 * @param av The argument vector.
 * @return 0 if arguments are valid, 1 otherwise.
 */
int			parse_arg(int ac, char **av);

/**
 * @brief Converts a string to an integer with overflow protection.
 * @param nptr The string to convert.
 * @return The integer value, or -1 on error.
 */
int			ft_atoi(char *nptr);

/**
 * @brief Checks if a character is a digit or whitespace.
 * @param c The character to check.
 * @return 1 if true, 0 if false.
 */
int			ft_isdigit_space(int c);

/**
 * @brief Checks if a character is a whitespace (space, tab, newline, etc).
 * @param c The character to check.
 * @return 1 if whitespace, 0 otherwise.
 */
int			is_space(char c);

/* ========================================================================== */
/*                              Initialization                                */
/* ========================================================================== */

/**
 * @brief Initializes the main simulation structure from arguments.
 * @param ac Argument count.
 * @param av Argument vector.
 * @param status Pointer to the status structure.
 * @return 0 on success, 1 on allocation failure.
 */
int			init_status(int ac, char **av, t_status *status);

/**
 * @brief Initializes all necessary mutexes (forks, print, meal, death).
 * @param status Pointer to the status structure.
 * @return 0 on success, 1 on failure.
 */
int			init_mutex(t_status *status);

/**
 * @brief Initializes the philosopher structures and assigns forks.
 * @param status Pointer to the status structure.
 * @return 0 on success, 1 on failure.
 */
int			init_philos(t_status *status);

/* ========================================================================== */
/*                              Time Management                               */
/* ========================================================================== */

/**
 * @brief Gets the current time in milliseconds.
 * @return Current timestamp in ms.
 */
long long	get_time(void);

/**
 * @brief Custom sleep function that periodically checks for death during wait.
 * @param time_ms Duration to sleep in milliseconds.
 * @param philo Pointer to the philosopher (for checking death status).
 */
void		ft_usleep(long long time_ms, t_philo *philo);

/* ========================================================================== */
/*                             Simulation Actions                             */
/* ========================================================================== */

/**
 * @brief Prints the status message of a philosopher with a timestamp.
 * @param philo Pointer to the philosopher.
 * @param status_msg The message to print (e.g., "is eating").
 * @param force_print If true, prints even if simulation has stopped.
 * @return 0 if printed, 1 if skipped due to simulation stop.
 */
int			print_status(t_philo *philo, char *status_msg, int force_print);

/**
 * @brief Logic for a philosopher taking forks, eating, and updating stats.
 * @param philo Pointer to the philosopher.
 */
void		philo_eat(t_philo *philo);

/**
 * @brief Logic for a philosopher sleeping.
 * @param philo Pointer to the philosopher.
 */
void		philo_sleep(t_philo *philo);

/**
 * @brief Logic for a philosopher thinking.
 * @param philo Pointer to the philosopher.
 */
void		philo_think(t_philo *philo);

/* ========================================================================== */
/*                              Thread Routines                               */
/* ========================================================================== */

/**
 * @brief Main thread entry point. Distributes routines based on philo count.
 * @param arg Pointer to the philosopher struct (void cast).
 * @return NULL.
 */
void		*routine(void *arg);

/**
 * @brief Special routine for the case of a single philosopher.
 * @param philo Pointer to the philosopher.
 * @return NULL.
 */
void		*one_philo(t_philo *philo);

/**
 * @brief Standard life cycle routine for philosophers (eat-sleep-think).
 * @param arg Pointer to the philosopher structure.
 * @return NULL.
 */
void		*philo_routine(void *arg);

/**
 * @brief Creates the philosopher threads.
 * @param status Pointer to the status structure.
 */
void		create_threads(t_status *status);

/**
 * @brief Waits for all philosopher threads to join.
 * @param status Pointer to the status structure.
 */
void		wait_threads(t_status *status);

/* ========================================================================== */
/*                            Monitoring & Control                            */
/* ========================================================================== */

/**
 * @brief Monitor thread (Big Brother) that checks for deaths and meals.
 * @param arg Pointer to the status structure.
 * @return NULL.
 */
void		*big_brother(void *arg);

/**
 * @brief Checks if a specific philosopher has starved.
 * @param philo Pointer to the philosopher to check.
 * @return 1 if died, 0 otherwise.
 */
int			check_death(t_philo *philo);

/**
 * @brief Checks if all philosophers have eaten the required number of meals.
 * @param status Pointer to the status structure.
 * @return 1 if all satisfied, 0 otherwise.
 */
int			is_all_ate_enough(t_status *status);

/**
 * @brief Sets the simulation stop flag thread-safely.
 * @param status Pointer to the status structure.
 * @param val The value to set (1 for stop usually).
 */
void		set_sim_stop(t_status *status, int val);

/* ========================================================================== */
/*                              Cleanup & Errors                              */
/* ========================================================================== */

/**
 * @brief Frees all allocated memory and destroys mutexes.
 * @param status Pointer to the status structure.
 */
void		free_the_chain(t_status *status);

/**
 * @brief Prints general "error" message and cleans up resources.
 * @param status Pointer to the status structure.
 */
void		msg_error(t_status *status);

/**
 * @brief Prints usage instructions to stdout.
 */
void		error(void);

#endif
