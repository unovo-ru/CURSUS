/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:58:35 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/08/31 18:04:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
arg_join works joining every arg in just 1:

	321 "45 87" 96
	"321 45 87 96"
	321 45 87 96
*/

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
		{
			free(str);
			print_error();
		}
		if (i > 0)
			str = ft_strjoin(str, " ");
		str = ft_strjoin(str, argv[i]);
		if (!str)
			print_error();
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
			free_array(new_num_list);
			print_error();
		}
		num[i] = (int)nbr;
		i++;
	}
	if (repeat_number(num, count) == 0)
	{
		free_array(new_num_list);
		print_error();
	}
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
	{
		free(number_list);
		print_error();
	}
	new_num_list = ft_split(number_list, ' ');
	if (!new_num_list)
	{
		free(number_list);
		return (0);
	}
	count = 0;
	while (new_num_list[count])
		count++;
	num = number_array(new_num_list, count);
	free_array(new_num_list);
	if (!num)
		return (0);
	return (num);
}

/*this function is the main function, it calls the rest of them*/

int	*final_input(char **str)
{
	int		size;
	char	*final_argument;
	int		*res;

	final_argument = arg_join(str);
	res = get_imput(final_argument);
	if (!res || !no_empty_arg(str))
	{
		free(res);
		print_error();
	}
	size = count_array(&str[1]);
	//printf("esto es el size --> %d\n\n", size);
	free(final_argument);
	return (res);
}


/*			TE HAS QUEDADO AQUI,
	TIENES QUE METER LOS NUMEROS EN NODOS
*/
