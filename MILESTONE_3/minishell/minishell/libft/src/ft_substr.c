/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:14:36 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/23 14:14:37 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*cpy;
	size_t			i;

	i = 0;
	if (start > ft_strlen(s))
	{
		cpy = (unsigned char *)malloc(1 * sizeof(char));
		if (!cpy)
			return (NULL);
		cpy[i] = '\0';
		return ((char *)cpy);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	cpy = (unsigned char *)malloc((len + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	ft_memcpy(cpy, s + start, len);
	cpy[len] = '\0';
	return ((char *)cpy);
}
