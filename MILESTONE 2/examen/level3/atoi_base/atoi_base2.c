/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:24:06 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/29 17:47:21 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int get_index(char c, char *str, int base)
{
	int i = 0;
	while (i < base)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char cap(char c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int sign = 1;
	int num = 0;
	int result = 0;
	char *base = "0123456789abcdef";

	if (str_base < 2 || str_base > 16)
		return (0);
	while (str[i] < 33)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (get_index(cap(str[i]), base, str_base) < 0)
			break ;
		num = get_index(cap(str[i]), base, str_base);
		result = (result * str_base) + num;
		i++;
	}
	return(result * sign);
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		int number = ft_atoi_base(av[1], atoi(av[2]));
		printf("%d", number);
	}
	printf("\n");
	return (0);
}
