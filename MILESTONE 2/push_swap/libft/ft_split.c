/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:36:36 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/08/30 17:19:29 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static size_t	ft_count_words(const char *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (!s)
		return ('\0');
	while (s[i] != '\0')
	{
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		if (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static size_t	ft_let_count(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	words;
	char	**myarray;

	i = 0;
	j = 0;
	words = ft_count_words(s, c);
	myarray = malloc(sizeof(char *) * (words + 1));
	if (!myarray)
		return (NULL);
	myarray[words] = NULL;
	while (s[i++] && j < words)
	{
		if (s[i] && s[i] != c)
		{
			myarray[j] = ft_substr(s, i, ft_let_count(&s[i], c));
			if (!myarray[j])
				return (free_array(myarray));
			j++;
			i = i + ft_let_count(s + i, c);
			continue ;
		}
	}
	return (myarray);
}
