/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 15:36:35 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/16 15:51:23 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 3)
	{
		char *str1 = av[1];
		char *str2 = av[2];
		int i = 0;
		int j = 0;
		int len = 0;
		while (str1[len])
			len++;
		while (str1[i] && str2[j])
		{
			if (str1[i] == str2[j])
				i++;
			j++;
		}
		if (i == len)
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}
