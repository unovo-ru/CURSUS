/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:14:36 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/23 14:14:37 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* ============================ */
/* ======= parse_utils ======== */
/* ============================ */

char	ft_quote_track(char c, char quote)
{
	if (!quote && (c == '\'' || c == '\"'))
		quote = c;
	else if (quote && c == quote)
		quote = 0;
	return (quote);
}

int	ft_redir_bucle_check(char *s, char quote)
{
	int		i;

	i = 0;
	while (s[i])
	{
		quote = ft_quote_track(s[i], quote);
		if ((s[i] == '>' || s[i] == '<') && !quote)
		{
			if (s[i] == '>' && s[i + 1] == '>')
				i += 2;
			else if (s[i] == '<' && s[i + 1] == '<')
				i += 2;
			else
				i++;
			while (s[i] && s[i] <= 32)
				i++;
			if (s[i] == '>' || s[i] == '<' || s[i] == '|' || s[i] == '\0')
				return (1);
			continue ;
		}
		i++;
	}
	return (0);
}
