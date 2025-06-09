/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isidigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 21:40:56 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/04/23 22:09:24 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

int	ft_isdigit(int c)
{
	if((c >= 48) && (c <= 57))
		return (1);
	else
		return (0);
}

int	main(void)
{
	printf ("%d\n", ft_isdigit('3'));
	printf ("%d\n", ft_isdigit('g'));
	
	printf ("%d\n", isdigit('4'));
        printf ("%d\n", isdigit('g'));
	return (0);
}
