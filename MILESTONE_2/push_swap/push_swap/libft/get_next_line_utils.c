/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:24:07 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/26 17:50:04 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_substr(char const *s, unsigned int start, size_t len, int flag)
{
	size_t	i;
	char	*myarray;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len = 0;
	myarray = (char *)malloc(sizeof(char) * len + 1);
	if (!myarray)
		return (NULL);
	i = 0;
	while (i < len)
	{
		myarray[i] = s[start + i];
		i++;
	}
	myarray[len] = '\0';
	if (flag)
		free ((char *)s);
	return (myarray);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*myarray;

	i = -1;
	myarray = (char *)malloc(sizeof (char)
			* (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!myarray)
		return (NULL);
	if (s1 == NULL)
		return ((char *)s2);
	if (s2 == NULL)
		return ((char *)s1);
	while (s1[++i] != '\0')
		myarray[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		myarray[i + j] = s2[j];
	myarray[i + j] = '\0';
	free (s1);
	return (myarray);
}
