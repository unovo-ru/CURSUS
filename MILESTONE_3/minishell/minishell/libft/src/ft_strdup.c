/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:14:36 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/23 14:14:37 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	unsigned char	*cpy;
	size_t			i;
	size_t			size;

	if (!s)
		return (NULL);
	i = 0;
	size = ft_strlen(s);
	cpy = (unsigned char *)malloc((size + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	while (i < size)
	{
		cpy[i] = (unsigned char)s[i];
		i++;
	}
	cpy[i] = '\0';
	return ((char *)cpy);
}
