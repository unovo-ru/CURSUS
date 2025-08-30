/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:34:12 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/24 22:40:31 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


void	ftunion(char *s1, char *s2)
{
	int	i = 0;

	while(s1[i])
	{
		unsigned char c = s1[i];
		if (s2[c] == 0)
		{
			write(1, &c, 1);
			s2[c] = 1;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	char	s2[256] = {};

	if (ac == 3)
	{
		ftunion(av[1], s2);
		ftunion(av[2], s2);
	}
	write(1, "\n", 1);
}
