/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:56:47 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/04/24 11:13:52 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isprint(int c)
{
	if((c >= 32) && (c <= 126))
		return (1);
	else
		return (0);
}

int	main(void)
{
	printf ("%d\n", ft_isprint('g'));
	printf ("%d\n", ft_isprint('2'));
	printf ("%d\n", ft_isprint(139));

	printf ("%d\n", isprint('g'));
        printf ("%d\n", isprint('2'));
        printf ("%d\n", isprint(139));
	return (0);
}
