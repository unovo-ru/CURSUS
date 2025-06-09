/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:19:23 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/04/24 11:34:48 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	
	while (s[i] != '\0')
		i++;
	return (i);
}

int	main(void)
{
	printf ("%ld\n", ft_strlen("Hola"));
	printf ("%ld", strlen("Hola"));
	return (0);
}
