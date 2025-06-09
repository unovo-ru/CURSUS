/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:24:20 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/04/27 20:24:29 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#inlcude "stdio.h"
#inlcude "unistd.h"

int	main(void)
{
	printf ("%ld\n", ft_strlen("Hola"));
	printf ("%ld", strlen("Hola"));
	
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
	return (0);
	
}
