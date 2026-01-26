/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:14:36 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/23 14:22:08 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_array_dup(char **s)
{
	char	**res;
	int		size;
	int		i;

	i = 0;
	size = 0;
	if (!s || !*s)
		return (NULL);
	while (s[size])
		size++;
	res = ft_calloc(size + 1, sizeof(char *));
	if (!res)
		return (NULL);
	while (s[i] && size > 0)
	{
		res[i] = ft_strdup(s[i]);
		if (!res[i])
			return (ft_free_all_array(res));
		i++;
		size--;
	}
	return (res);
}
