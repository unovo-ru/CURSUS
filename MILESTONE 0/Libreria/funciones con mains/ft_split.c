/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:36:36 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/05/09 18:58:56 by unovo-ru         ###   ########.fr       */
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
//	printf ("tengo [ %zu ] palabras\n", count);
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

/* static size_t	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	j;j = 0;
	size_t	count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (s[i] != c)
			j = i;
		while (s[j] != c)
		{
			j++;
			i++;
			if (s[j] == c)
				count++;
		}
		i++;
	}
	return (count);
} */

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	words;
	char	**myarray;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	myarray = malloc(sizeof(char *) * (words + 1));
	if (!myarray)
		return (NULL);
	myarray[words] = NULL;
	while (s[i] && j < words)
	{
		if (s[i] != c)
		{
			myarray[j] = ft_substr(s, i, ft_let_count(&s[i], c));
			if (!myarray[j])
				return (free_array(myarray));
			j++;
			i = i + ft_let_count(s + i, c);
		}
		i++;
	}
	return (myarray);
}

	/*	wrds[ft_count_words(s, c)] = NULL;
	i = 0;
	l = -1;
	while int	main(void)
{
	const char	*s = "hola";
	char		**split;
	int			i;

	i = -1;
	split = ft_split(s, ' ');
	while (split[++i])
	{
		printf ("%s\n", split[i]);
		free(split[i]);
	}
	free(split);
	return (0);
}(s[i])
	{
		j = 0;
		while (s[i + j] != c)
			j++;
		if (j > 0 && ++l < (ft_count_words(s, c)))
		{
			wrds[l] = ft_substr(s, i, j);
			if (!wrds[l])
				return (NULL);
		}
		i = i + j;
		i++;
	}
	return (wrds);
}*/
int	main(void)
{
	const char	*s = "   h   ol a   ";
	char		**split;
	int			i;

	i = -1;
	split = ft_split(s, '\0');
	while (split[++i])
	{
		printf ("%s\n", split[i]);
		free(split[i]);
	}
	free(split);
	return (0);
}