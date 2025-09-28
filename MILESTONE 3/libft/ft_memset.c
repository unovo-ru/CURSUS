/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memeset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:42:24 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/04/24 12:07:13 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*copy;
	size_t			i;

	i = 0;
	copy = (unsigned char *)s;
	while (i < n)
	{
		copy[i] = c;
		i++;
	}
	s = (void *)copy;
	return (s);
}
