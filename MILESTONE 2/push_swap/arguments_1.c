/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:58:35 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/08/28 13:20:37 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
arg_join works joining every arg in just 1:

	321 "45 87" 96
	"321 45 87 96"
	321 45 87 96
*/

/*arrglar " " para que de error*/

char	*arg_join(char **argv)
{
	int		i;
	char	*str;

	i = 1;
	str = ft_strdup("");
	if (!str)
		return (NULL);
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			print_error();
		if (i > 0)
			str = ft_strjoin(str, " ");
		str = ft_strjoin(str, argv[i]);
		if (!str)
			return (NULL);
		i++;
	}
	return (str);
}

/*this function tells me that the imput is valid, it takes only numbers and
valid signs '-'*/

int	arg_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			i++;
			continue ;
		}
		if ((str[i] == '-' ) && (i == 0 || str[i - 1] == ' '))
		{
			i++;
			if (!ft_isdigit(str[i]))
				return (0);
		}
		else if (!ft_isdigit(str[i]))
			return (0);
		else
			i++;
	}
	return (1);
}


/*this function tells me if the number is correct, just an int*/

int	is_min_or_max(long int nbr)
{
	if (nbr >= INT_MIN && nbr <= INT_MAX)
		return (1);
	return (0);
}

/*this fuction casts and fixes every number in an array to proof tha
no one is duplicated*/

int	*number_array(char **new_num_list, int count)
{
	int		i;
	long	nbr;
	int		*num;

	num = (int *)malloc(sizeof(int) * count);
	if (!num)
		return (0);
	i = 0;
	while (i < count)
	{
		nbr = ft_atol(new_num_list[i]);
		if (!is_min_or_max(nbr))
		{
			free(num);
			print_error();
		}
		num[i] = (int)nbr;
		i++;
	}
	if (repeat_number(num, count) == 0)
		print_error();
	return (num);
}

/*in this function i call all the others functions to proof if is valid
the argument and join every one of them*/

int	*get_imput(char *number_list)
{
	int		*num;
	char	**new_num_list;
	int		count;

	if (!arg_valid(number_list))
		print_error();
	new_num_list = ft_split(number_list, ' ');
	if (!new_num_list)
		return (0);
	count = 0;
	while (new_num_list[count])
		count++;
	num = number_array(new_num_list, count);
	free_array(new_num_list);
	if (!num)
		return (0);
	return (num);
}

/*hacer una funcion que averigue si se repiten valores en un array
de ints (CREAR PRIMERO LA FUNCION QUE COLOQUE LOS NUMEROS EN UNA ARRAY
DE INTS)*/
