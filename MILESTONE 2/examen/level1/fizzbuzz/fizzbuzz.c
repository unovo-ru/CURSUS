/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:12:05 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/09 17:49:15 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int nbr)
{
	char c;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	c = (nbr % 10) + '0';
	write (1, &c, 1);
}

void fizz_buzz(void)
{
	int i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write (1, "fizzbuzz\n", 9);
		if (i % 3 == 0)
			write (1, "fizz\n", 5);
		if (i % 5 == 0)
			write (1, "buzz\n", 5);
		else
		{
			ft_putnbr(i);
			write (1, "\n", 1);
		}
		i++;
	}
}

int main(void)
{
	fizz_buzz();
	return (0);
}
