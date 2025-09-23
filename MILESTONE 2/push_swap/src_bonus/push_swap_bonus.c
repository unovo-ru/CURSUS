/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:02:21 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/23 20:02:21 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

bool	is_sorted(t_node **stack)
{
	t_node	*aux;

	aux = (*stack);
	while (1)
	{
		if (aux->data > aux->next->data)
			return (false);
		aux = aux->next;
		if (aux == (*stack))
			return (true);
	}
	return (true);
}

void	gnl_call(t_node **stack_a, t_node **stack_b)
{
	char	*str;

	str = ft_strdup("");
	while (str)
	{
		free(str);
		str = get_next_line(0);
		move_if(str, stack_a, stack_b);
	}
	if (stack_size(stack_b))
	{
		free_nodes(stack_a);
		free_nodes(stack_b);
		ft_printf("KO\n");
		exit (0);
	}
	if (is_sorted(stack_a) == true)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	move_if(char *str, t_node **stack_a, t_node **stack_b)
{
	if (ft_strncmp("ra", str, 2))
		ra(stack_a);
	else if (ft_strncmp("rra", str, 2))
		rra(stack_a);
	else if (ft_strncmp("rb", str, 2))
		rb(stack_b);
	else if (ft_strncmp("rrb", str, 2))
		rrb(stack_b);
	else if (ft_strncmp("rr", str, 2))
		rr(stack_a, stack_b);
	else if (ft_strncmp("rrr", str, 2))
		rrr(stack_a, stack_b);
	else if (ft_strncmp("sa", str, 2))
		sa(stack_a);
	else if (ft_strncmp("sb", str, 2))
		sb(stack_b);
	else if (ft_strncmp("ss", str, 2))
		ss(stack_a, stack_b);
	else if (ft_strncmp("pa", str, 2))
		pa(stack_a, stack_b);
	else if (ft_strncmp("pb", str, 2))
		pb(stack_b, stack_a);
	else
		ft_free_stacks(stack_a, stack_b);
}

t_node	*push_swap(char **str)
{
	int		size;
	char	*final_argument;
	int		*res;
	t_node	*stack;
	t_node	*stack_b;

	stack = NULL;
	stack_b = NULL;
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
		gnl_call(&stack, &stack_b);
	}
	else
		free(res);
	free(final_argument);
	return (stack);
}
