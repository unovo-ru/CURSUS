/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:45:15 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/15 09:33:51 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	main(int ac, char ** av)
{
	int i = 1;
	int j = 0;

	if (ac >= 1)
	{	
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				if ((av[i][j] >= 'a' && av[i][j] <= 'z') && (av[i][j + 1] < 33))
					av[i][j] = av[i][j] - 32;
				else if ((av[i][j] >= 'A' && av[i][j] <= 'Z') && (av[i][j + 1] > 33))
					av[i][j] = av[i][j] + 32;
				write (1, &av[i][j], 1);
				j++;
			}
			write (1, "\n", 1);
			i++;
		}
	}
	else 
		write (1, "\n", 1);	
	return (0);
}


/*
int	main(int ac, char **av)
{
	int	i = 1;
	
	if (ac == 1)
		write(1, "\n", 1);
	while (ac > i)
	{
		cap(av[i]);
		write(1, "\n", 1);
		i++;
	}
}*/
