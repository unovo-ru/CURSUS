/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblstr_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:14:36 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/23 14:22:29 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_dblstr_join(char **str)
{
	char	*res;
	char	*tmp;
	int		i;

	i = -1;
	res = ft_strdup("");
	if (!res)
		return (NULL);
	while (str[++i])
	{
		if (i > 0)
		{
			tmp = ft_strjoin(res, " ");
			free(res);
			res = tmp;
			if (!res)
				return (NULL);
		}
		tmp = ft_strjoin(res, str[i]);
		free(res);
		res = tmp;
		if (!res)
			return (NULL);
	}
	return (res);
}
