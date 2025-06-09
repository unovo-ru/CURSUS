/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 09:36:40 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/04/24 10:02:38 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isalnum(int c)
{
	if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) || ((c >= 48) && (c <= 57)))
		return (1);
	else
		return (0);
}

int	main(void)
{
	printf ("%d\n", ft_isalnum('g'));
	printf ("%d\n", ft_isalnum('2'));
	printf ("%d\n", ft_isalnum('`'));

	printf ("%d\n", isalnum('g'));
        printf ("%d\n", isalnum('2'));
        printf ("%d\n", isalnum('`'));
	return (0);


}
