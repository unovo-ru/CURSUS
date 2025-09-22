/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:01:44 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/06 18:28:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*push_swap_extension(char *str, char **arg)
{
	int	*res;

	if (!str)
		free(str);
	res = get_imput(str);
	if (!res || !no_empty_arg(arg))
	{
		free(res);
		free(str);
		print_error();
	}
	return (res);
}

t_node	*push_swap(char **str)
{
	int		size;
	char	*final_argument;
	int		*res;
	t_node	*stack;

	stack = NULL;
	final_argument = arg_join(str);
	res = push_swap_extension(final_argument, str);
	size = count_array(final_argument);
	if (is_correct(res, size) == 1)
	{
		stack = node_aplication(res, size);
		if (!stack)
		{
			free(final_argument);
			return (NULL);
		}
		index_node(&stack, size);
		position_node(&stack);
		select_hc(size, &stack);
	}
	else
		free(res);
	free(final_argument);
	return (stack);
}
