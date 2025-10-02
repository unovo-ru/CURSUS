/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:40:35 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/04/25 16:52:18 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*daux;
	const unsigned char	*saux;
	size_t				i;

	daux = (unsigned char *)dest;
	saux = (const unsigned char *)src;
	if (!daux && !saux)
		return (NULL);
	i = 0;
	if (daux < saux)
		ft_memcpy(daux, saux, n);
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			daux[i] = saux[i];
		}
	}
	return (daux);
}
