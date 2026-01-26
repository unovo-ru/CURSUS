/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:14:36 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/23 14:14:37 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*c;
	const unsigned char	*o;

	c = (unsigned char *)dest;
	o = (const unsigned char *)src;
	i = n;
	if ((!dest && !src))
		return (NULL);
	if (o < c)
	{
		while (i > 0)
		{
			i--;
			c[i] = o[i];
		}
	}
	else
		ft_memcpy(c, o, n);
	return ((void *)dest);
}
