/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:14:36 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/23 14:21:51 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

/* ============================ */
/* ========== signals ========= */
/* ============================ */

/**
 * @brief Sets up signal handlers for interactive mode.
 * @return 0 on success, 1 on error.
 * @note SIGINT displays prompt on new line. SIGQUIT ignored.
 */
int		ft_hugin_signal(void);

/**
 * @brief Signal handler for interactive mode (Hugin).
 * @param sig Signal number received.
 * @note Handles SIGINT: prints newline, resets prompt, sets
 *       g_status to 130.
 */
void	ft_hugin_handler(int sig);

/**
 * @brief Sets up signal handlers for heredoc input mode.
 * @return 0 on success, 1 on error.
 * @note SIGINT closes STDIN and sets g_status. SIGQUIT ignored.
 */
int		ft_munin_signal(void);

/* ============================ */

/* ============================ */
/* ===== heimdall_signals ===== */
/* ============================ */

/**
 * @brief Handles signals received by child processes.
 * @param sig Signal number received.
 */
void	ft_child_handler(int sig);

/**
 * @brief Sets up signal handlers for child processes.
 * @return 0 on success, -1 on error.
 */
int		ft_child_signal(void);

/**
 * @brief Sets up signal handlers to ignore signals during execution.
 * @return 0 on success, 1 on error.
 * @note Ignores SIGINT and SIGQUIT. Used in parent process.
 */
int		ft_odin_signal(void);

/**
 * @brief Restores default signal handlers for child processes.
 * @return 0 on success, 1 on error.
 * @note Sets SIGINT and SIGQUIT to SIG_DFL.
 */
int		ft_odinson_signal(void);

/* ============================ */

#endif