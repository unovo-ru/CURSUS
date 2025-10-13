/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:16:08 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/13 13:17:26 by unovo-ru         ###   ########.fr       */
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

/* ========================================================================== */
/*                                   MACROS                                   */
/* ========================================================================== */

# define ERROR_ARGS		"Error: Invalid number of arguments\n"
# define ERROR_INPUT	"Error: Invalid input\n"
# define ERROR_MALLOC	"Error: Memory allocation failed\n"
# define ERROR_THREAD	"Error: Thread creation failed\n"
# define ERROR_MUTEX	"Error: Mutex initialization failed\n"

# define MSG_FORK		"has taken a fork"
# define MSG_EAT		"is eating"
# define MSG_SLEEP		"is sleeping"
# define MSG_THINK		"is thinking"
# define MSG_DIED		"died"

#endif