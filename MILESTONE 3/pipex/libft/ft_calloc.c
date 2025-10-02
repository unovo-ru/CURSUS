/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:30:12 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/05/03 13:24:11 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	int		*myarray;
	size_t	i;

	i = 0;
	myarray = (int *)malloc(nmemb * size);
	if (!myarray)
		return (NULL);
	while (myarray[i] != '\0')
	{
		myarray[i] = 0;
		i++;
	}
	return ((void *)myarray);
}
