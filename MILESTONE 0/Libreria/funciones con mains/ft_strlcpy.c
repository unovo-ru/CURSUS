/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 20:01:58 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/04/26 21:45:27 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	f;

	f = ft_strlen(src);
	if (size == 0)
		return (f);
	if (dest == NULL)
		return (f);
	i = 0;
	while ((src[i] != '\0') && (i < (size - 1)))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (f);

}

int main(void)
{
   char src[] = "Hello, World!";
    char dest[20];
    size_t result;
    size_t buffer_size = sizeof(dest);

	// Caso 1: Copia normal con espacio suficiente
    result = ft_strlcpy(dest, src, buffer_size);
   printf("Caso 1:\n");
    printf("Fuente: '%s'\n", src);
    printf("Destino: '%s'\n", dest);
    printf("Longitud de la fuente: %zu\n", result);
   printf("Tamaño del buffer: %zu\n\n", buffer_size);
}
