/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:59:56 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/04/29 18:47:22 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*aux;
	char	cm;

	i = 0;
	cm = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == cm)
		{
			aux = (char *)&s[i];
			return (aux);
		}
		i++;
	}
	if (cm == '\0')
	{
		aux = (char *)&s[i];
		return (aux);
	}
	else
		return (NULL);
}
