/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:15:12 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/28 18:38:59 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void inter(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	int ascii[256] = {0};
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j] && ascii[(int)s1[i]] == 0)
			{
				write (1, &s1[i], 1);
				ascii[(int)s1[i]] = 1;
				
			}
			j++;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 3)
		inter(av[1], av[2]);
	write (1, "\n", 1);
	return (0);
}
