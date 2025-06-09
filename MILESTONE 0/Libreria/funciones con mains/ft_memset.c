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
#include <string.h>
#include <stdio.h>

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

int main() {
    char buffer[10];

    // Usar mi ft_memset para llenar el buffer con el valor 'A' (en ASCII 65)
    ft_memset(buffer, 'A', sizeof(buffer));

    // Imprimir el contenido de buffer
    printf("El buffer lleno con 'A': %s\n", buffer);

    // Usar memset para llenar los primeros 10 caracteres del buffer con 0
    ft_memset(buffer, 0, 10);

    // Imprimir el contenido del buffer después de poner ceros
    printf("El buffer después de memset(0): %s\n", buffer);
    
    
    // Usar memset para llenar el buffer con el valor 'A' (en ASCII 65)
    memset(buffer, 'A', sizeof(buffer));

    // Imprimir el contenido de buffer
    printf("El buffer lleno con 'A': %s\n", buffer);

    // Usar memset para llenar los primeros 10 caracteres del buffer con 0
    memset(buffer, 0, 10);

    // Imprimir el contenido del buffer después de poner ceros
    printf("El buffer después de memset(0): %s\n", buffer);


    return 0;
}
