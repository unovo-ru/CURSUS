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

#include <string.h>
#include <stdio.h>
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

//int	main(void)
//{
//	const char str1[] = "Hello world";
//	char buscar1 = 'w';
//	size_t n1 = strlen(str1);

//	void *resultado1 = ft_memchr(str1, buscar1, n1);
//	if (resultado1 != NULL)
//	{	
//		printf("Caso 1: '%c' encontrado en la posición %ld.\n", 
//		buscar1, (char *)resultado1 - str1);
//	}
//	else
//	{
//		printf("Caso 1: '%c' no encontrado.\n", buscar1);
//	}
//}
