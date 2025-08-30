/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 19:55:22 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/21 22:43:11 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] < 33)
			return (-1);
		i++;
	}
	return (i);
}

void rostring(char *str)
{
	int i = 0;
	while (str[i] < 33)
		i++;
	int j = i;
	int flag = 1;
	if (ft_strlen(str) > 0)
	{
		i = ft_strlen(str);
		write (1, str, i);
		return ;
	}
	while (str[j] > 33)
		j++;
	while (str[j] < 33)
		j++;
	while (str[j])
	{
		if (str[j] && str[j] > 32)
		{
			flag = 0;
			while (str[j] && str[j] > 32)
			{
				write (1, &str[j], 1);
				j++;
			}
		}
		else if (str[j] && str[j] < 33)
		{
			flag = 1;
			write (1, " ", 1);
			while (str[j] && str[j] < 33)
				j++;
		}
	}
	if (!flag)
		write (1, " ", 1);
	while (str[i] > 32)
	{
		write (1, &str[i], 1);
		i++;
	}



}

int main(int ac, char **av)
{
	if (ac == 2)
		rostring(av[1]);
	write (1, "\n", 1);
	return 0;
}
