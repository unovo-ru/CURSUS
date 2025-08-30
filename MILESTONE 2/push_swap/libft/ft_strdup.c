/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:42:58 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/05/14 13:53:06 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*myarray;
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	myarray = (char *)malloc(sizeof(char) * (i + 1));
	if (!myarray)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		myarray[i] = s[i];
		i++;
	}
	myarray[i] = '\0';
	return (myarray);
}
