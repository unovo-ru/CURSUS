/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 18:04:41 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/05/14 10:09:05 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
	while ((i < len + 1) && (s[i] != '\0'))
	{
		ft_memcpy(myarray, s + start, len);
		i++;
	}
	myarray[len] = '\0';
	return (myarray);
}
