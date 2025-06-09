/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:05:17 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/05/14 12:22:11 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	rev_pair(unsigned int i, char c)
{
	if ((c >= 'a' && c <= 'z') && (i % 2 == 0))
		return (c - 32);
	else
		return (c);

}


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

int	main(void)
{
	char	*s = "hola mundo";
	char *myarray = ft_strmapi(s, rev_pair);

	printf ("este es mi original %s\n", s);
	printf ("este es con la funcion %s\n", myarray);
	free(myarray);
	return(0);
}
