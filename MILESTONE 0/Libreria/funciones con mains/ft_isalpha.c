/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:21:41 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/04/22 15:57:14 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ctype.h>
#include <stdio.h>

int	ft_isalpha(int c)
{
	if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')))
		return (1);
	else 
		return (0);
}

int	main(void)
{
	int	c;
	
	c = 8;

	printf ("este es el ft: %d\neste es el original: %d\n", ft_isalpha(c), isalpha(c));
	return (0);

}
