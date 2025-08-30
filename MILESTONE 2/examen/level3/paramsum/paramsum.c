/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:01:20 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/16 16:21:43 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void put_nbr(int num)
{
	char c;
	while (num > 9)
	{
		c = num % 10 + '0';
		num /= 10;
		write(1, &c, 1);
	}
	c = num + '0';
	write (1, &c, 1);
}


int main(int ac, char **av)
{
	int i = 0;
	while (av[i])
		i++;
	i--;
	if (i < 10)
	{
		char c = i + '0';
		write (1, &c, 1);
	}
	else if (i > 10)
		put_nbr(i);
	write (1, "\n", 1);
	return (0);
}
