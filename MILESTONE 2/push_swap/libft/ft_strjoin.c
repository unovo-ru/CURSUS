/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:07:30 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/08/13 18:14:13 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
	//free(s1);
	return (myarray);
}
