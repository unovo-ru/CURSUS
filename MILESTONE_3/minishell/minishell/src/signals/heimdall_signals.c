/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heimdall_signals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:14:36 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/23 14:14:37 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* =============================== */
/* ====== heimdall_signals ======= */
/* =============================== */

void	ft_child_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_status = 130;
		ft_fprintf(1, "\n");
	}
	else if (sig == SIGQUIT)
		g_status = 131;
}

int	ft_child_signal(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &ft_child_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGINT, &sa, NULL) == -1)
		return (1);
	if (sigaction(SIGQUIT, &sa, NULL) == -1)
		return (1);
	return (0);
}

int	ft_odin_signal(void)
{
	struct sigaction	sa;
	struct sigaction	sa_ign;

	ft_memset(&sa, 0, sizeof(sa));
	ft_memset(&sa_ign, 0, sizeof(sa_ign));
	sa.sa_handler = SIG_IGN;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGINT, &sa, NULL) == -1)
		return (ft_pd_error(ERR_SIGNAL, "SIGINT", 1));
	sa_ign.sa_handler = SIG_IGN;
	sa_ign.sa_flags = SA_RESTART;
	sigemptyset(&sa_ign.sa_mask);
	if (sigaction(SIGQUIT, &sa_ign, NULL) == -1)
		return (ft_pd_error(ERR_SIGNAL, "SIGQUIT", 1));
	return (0);
}

int	ft_odinson_signal(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = SIG_DFL;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGINT, &sa, NULL) == -1)
		return (ft_pd_error(ERR_SIGNAL, "SIGINT", 1));
	if (sigaction(SIGQUIT, &sa, NULL) == -1)
		return (ft_pd_error(ERR_SIGNAL, "SIGQUIT", 1));
	return (0);
}
