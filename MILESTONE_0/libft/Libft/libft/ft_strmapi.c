/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:05:17 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/05/14 14:19:44 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*myarray;

	i = 0;
	myarray = ft_strdup(s);
	if (!myarray)
		return (NULL);
	while (myarray[i])
	{
		myarray[i] = f(i, myarray[i]);
		i++;
	}
	return (myarray);
}
