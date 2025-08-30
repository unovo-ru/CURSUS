/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 09:56:09 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/05/01 11:33:34 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		p;
	unsigned char		*aux;

	aux = (unsigned char *)s;
	p = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (aux[i] == p)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
