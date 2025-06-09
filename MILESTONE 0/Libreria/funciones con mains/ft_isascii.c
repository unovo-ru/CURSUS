/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:18:46 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/04/24 10:28:45 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isascii(int c)
{
	if ((c <= 0) || (c >= 127))
		return (0);
	else
		return (1);
}

int	main(void)
{
	printf ("%d\n", ft_isascii('g'));
	printf ("%d\n", ft_isascii('2'));
	printf ("%d\n", ft_isascii(139));

	printf ("%d\n", isascii('g'));
        printf ("%d\n", isascii('2'));
        printf ("%d\n", isascii(139));
	return (0);
}
