/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:26:16 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/04/29 19:27:31 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	cm;
	char	*aux;

	cm = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == cm)
		{
			aux = (char *)&s[i];
			return (aux);
		}
		i--;
	}
	if (s[i] == cm)
	{
		aux = (char *)&s[i];
		return (aux);
	}
	else
		return (NULL);
}
