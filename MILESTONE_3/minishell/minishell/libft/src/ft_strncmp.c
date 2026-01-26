/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:14:36 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/23 14:14:37 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = 0;
	while ((s1[i] || s2[i]) && (i < n) && (res == 0))
	{
		if (s1[i] != s2[i])
			res = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	return ((int)res);
}
