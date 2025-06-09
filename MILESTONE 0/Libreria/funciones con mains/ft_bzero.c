/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:43:17 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/04/24 19:08:30 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*aux;
	size_t		i;

	i = 0;
	aux = (unsigned char *) s;
	while (i < n)
	{	
		aux[i] = '\0';
		i++;
	}
	s = (void *)aux;
}

int	main(void)
{
	char	c[] = "hola";
	int	i;

	i = 0;
	printf ("%s\n", c);
	ft_bzero(c, 2);
	while (i < 4)
	{
		printf("%c", c[i]);
		i++;
	}
	return (0);
}
