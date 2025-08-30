/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:17:40 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/17 22:16:15 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char    **ft_split(char *str)
{
        char **word = malloc(10000000 *sizeof(char *));
        int i = 0;
        char *start;
        if (!word)
                return (NULL);
        while (*str)
        {
                while (*str < 33)
                        str++;
                if (!str)
                        break;
                start = str;
                while (*str && !(*str < 33))
                        str++;
                word[i] = malloc(str - start + 1);
                if (!word[i])
                        return (NULL);
                int j = 0;
                while (start < str)
                        word[i][j++] = *start++;
                word[i][j] = '\0';
                i++;
        }
        word[i] = NULL;
        return (word);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char **words = ft_split(av[1]);
		int	i = 0;
		while (words[i])
		{
			printf("palabra %d: %s\n", i + 1, words[i]);
			free(words[i]);
			i++;
		}
		free(words);
	}
	return (0);
}
