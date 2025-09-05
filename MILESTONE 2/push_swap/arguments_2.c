/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:05:42 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/05 17:46:01 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*this function frees the array for memory leaks*/

char	**free_array(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

/*this function tells me if there are repeted numbers*/

int	repeat_number(int *numbers, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (numbers[i] == numbers[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*print an error message and exit*/

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

/*this function tells me error if there is an empty argument*/

int	no_empty_arg(char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	j = 0;
	flag = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (ft_isdigit((int)argv[i][j]))
				flag = 1;
			j++;
		}
		i++;
	}
	if (flag == 0)
		return (0);
	return (1);
}

/*this function tells me if the number is correct, just an int*/

int	is_min_or_max(long int nbr)
{
	if (nbr >= INT_MIN && nbr <= INT_MAX)
		return (1);
	return (0);
}
