/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:28:12 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/17 20:02:17 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int n;

	if (a == 0 ||b == 0)
		return (0);
	if (a > b)
		n = a;
	else
		n = b;
	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		n++;
	}

}
int main(int ac, char **av)
{
	if (ac == 3)
	{
		int x = atoi(av[1]);
		int y = atoi(av[2]);
		int result = lcm(x , y);
		printf("%d", result);
	}
}
