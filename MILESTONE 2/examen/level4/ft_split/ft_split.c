/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:46:30 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/15 09:39:13 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>

char	**ft_split(char *str)
{
	char **word = (100 *sizeof(char *));
	int i = 0;
	char *start;
	if (!word)
		return (NULL);
	while (*str)
	{
		while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
		if (!str)
			break;
		start = str;
		while (*str && !(*str == ' ' || *str == '\t' || *str == '\n'))
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
