/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:58:35 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/06 18:35:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arg_join_extension(char *str)
{
	if (!str)
	{
		free(str);
		return ;
	}
}

char	*arg_join(char **argv)
{
	int		i;
	char	*str;

	i = 1;
	str = ft_strdup("");
	arg_join_extension(str);
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
		{
			free(str);
			print_error();
		}
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
		return (NULL);
	i = 0;
	while (i < count && new_num_list)
	{
		nbr = ft_atol(new_num_list[i]);
		if (!is_min_or_max(nbr))
		{
			free(num);
			return (0);
		}
		num[i] = (int)nbr;
		i++;
	}
	if (!repeat_number(num, count))
	{
		free(num);
		return (0);
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
		return (0);
	new_num_list = ft_split(number_list, ' ');
	if (!new_num_list)
		return (0);
	count = 0;
	while (new_num_list[count])
		count++;
	num = number_array(new_num_list, count);
	free_array(new_num_list);
	if (!num)
	{
		free(num);
		return (0);
	}
	return (num);
}


