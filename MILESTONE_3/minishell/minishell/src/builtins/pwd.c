/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:14:36 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/23 14:14:37 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ================= //
// ====== PWD ====== //
// ================= //

int	ft_pwd(char **env)
{
	char	*buffer;

	buffer = ft_get_var_value(env, "PWD");
	if (!buffer)
	{
		buffer = getcwd(NULL, 0);
		if (!buffer)
			return (ft_pd_error(ERR_PWD, NULL, 1));
	}
	ft_printf("%s\n", buffer);
	free(buffer);
	return (0);
}
