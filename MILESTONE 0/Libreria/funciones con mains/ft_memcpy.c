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

#include <string.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
/*	char *d;
	char *s;

	if (!dest || !src)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	while(n--)
		d[n] = s[n];
	return (dest);
*/




	
	char	*daux;
	char	*saux;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	daux = (char *)dest;
	saux = (char *)src;
	i = 0;
	while (i < n && daux[i] && saux[i])
	{
		daux[i] = saux[i];
		i++;
	}
	return (dest);
//	dest = (void *)daux;
//	src = (void *)saux;
}

int	main(void)
{
	char src[] = "hola";
	char dest[] = "";
//	int = x;

//	x = 0;
// 	src = "hola";
//	

//	printf ("%s\n", src);
//	ft_memcpy (dest, src, 1);
//	printf ("%s\n", dest);
	printf ("%s", (char *)ft_memcpy(dest, src, 4));
	//while (x < 5)
//	{
//		printf("%c", dest[x]);
//		x++;
//	}
	return (0);

	//printf(,(char *) ft_memcpy(dest, scr, 5));
}
