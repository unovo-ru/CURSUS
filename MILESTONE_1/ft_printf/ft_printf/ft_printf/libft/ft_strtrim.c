/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:20:50 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/05/06 15:28:47 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_coincidence(const char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*myarray;

	i = 0;
	if ((!s1) || (!set))
		return (NULL);
	len = ft_strlen(s1) - 1;
	while (s1[i] && ft_coincidence(set, s1[i]) == 1)
		i++;
	while (len > i && ft_coincidence(set, s1[len]) == 1)
		len--;
	myarray = ft_substr(s1, i, (len - i + 1));
	if (!myarray)
		return (NULL);
	return (myarray);
}
