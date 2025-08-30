/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:59:32 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/22 16:54:17 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int i = 0;
		char *str = av[1];
		while (str[i] && str[i] <= 32)
			i++;
		while (str[i])
		{
			if(str[i] && str[i] > 32)
				write (1, &str[i], 1);
			if (str[i] <= 32 && str[i + 1] > 32)
				write (1, &str[i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
