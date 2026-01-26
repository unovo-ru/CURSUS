/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:14:36 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/23 14:14:37 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	checkfunc(const char *set, const char s1)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	while (set[i] && res == 0)
	{
		if (set[i] == s1)
			res = 1;
		i++;
	}
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned char	*new_str;
	size_t			j;
	int				i;
	int				size;

	i = 0;
	size = ft_strlen(s1);
	j = size - 1;
	if (!s1 || !set)
		return (NULL);
	while (checkfunc(set, s1[j]) == 1)
		j--;
	while (checkfunc(set, s1[i]) == 1)
		i++;
	new_str = (unsigned char *)ft_substr(s1, i, (j - i) + 1);
	if (!new_str)
		return (NULL);
	return ((char *)new_str);
}
