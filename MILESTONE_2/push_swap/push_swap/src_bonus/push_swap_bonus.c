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

	if (!stack || !*stack)
		return (false);
	aux = (*stack);
	while (1)
	{
		if (aux->data > aux->next->data)
			return (false);
		aux = aux->next;
		if (aux == (*stack)->prev)
			return (true);
	}
	return (true);
}

void	gnl_call(t_node **stack_a, t_node **stack_b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		move_if(str, stack_a, stack_b);
		free(str);
	}
	if (is_sorted(stack_a) == true && !(*stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	move_if(char *str, t_node **stack_a, t_node **stack_b)
{
	if (ft_strncmp("ra\n", str, 3) == 0)
		ra(stack_a);
	else if (ft_strncmp("rra\n", str, 4) == 0)
		rra(stack_a);
	else if (ft_strncmp("rb\n", str, 3) == 0)
		rb(stack_b);
	else if (ft_strncmp("rrb\n", str, 4) == 0)
		rrb(stack_b);
	else if (ft_strncmp("rr\n", str, 3) == 0)
		rr(stack_a, stack_b);
	else if (ft_strncmp("rrr\n", str, 4) == 0)
		rrr(stack_a, stack_b);
	else if (ft_strncmp("sa\n", str, 3) == 0)
		sa(stack_a);
	else if (ft_strncmp("sb\n", str, 3) == 0)
		sb(stack_b);
	else if (ft_strncmp("ss\n", str, 3) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp("pa\n", str, 3) == 0)
		pa(stack_b, stack_a);
	else if (ft_strncmp("pb\n", str, 3) == 0)
		pb(stack_a, stack_b);
	else
		ft_free_stacks(stack_a, stack_b, str);
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
	stack = node_aplication(res, size);
	if (!stack)
	{
		free(final_argument);
		return (NULL);
	}
	free(final_argument);
	gnl_call(&stack, &stack_b);
	if (stack_b)
	{
		free_nodes(&stack_b);
		stack_b = NULL;
	}
	return (stack);
}
