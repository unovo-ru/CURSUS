/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:24:33 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/28 18:37:11 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	char *s1 = av[1];
	char *s2 = av[2];
	int i = 0;
	int j = 0;
	int ascii[256] = {0};

	if (ac == 3)
	{
		while (s1[i])
		{
			if (ascii[(int)s1[i]] == 0)
			{
				write (1, &s1[i], 1);
				ascii[(int)s1[i]] = 1;
			}
			i++;
		}
		while (s2[j])
		{
			if (ascii[(int)s2[j]] == 0)
			{
				write (1, &s2[j], 1);
				ascii[(int)s2[j]] = 1;
			}
			j++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
