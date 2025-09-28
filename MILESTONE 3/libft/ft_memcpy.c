/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:28:28 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/04/24 21:04:06 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*daux;
	unsigned char		*saux;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	daux = (unsigned char *)dest;
	saux = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		daux[i] = saux[i];
		i++;
	}
	return (dest);
}
