/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:29:37 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/11 13:45:55 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_2(t_node **stack_a)
{
	ra(stack_a);
}

void	sort_3(t_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->data;
	b = (*stack_a)->next->data;
	c = (*stack_a)->next->next->data;
	if (a < b && b > c && a < c)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
	else if (a > b && b > c && a > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a > b && b < c && a < c)
		sa(stack_a);
}

void	sort_4(t_node **stack_a, t_node **stack_b)
{
	int		min;

	min = is_min(stack_a);
	while ((*stack_a)->data != min)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_b, stack_a);
}

void	sort_5(t_node **stack_a, t_node **stack_b)
{
	int	min;

	min = is_min(stack_a);
	while ((*stack_a)->data != min)
		ra(stack_a);
	pb(stack_a, stack_b);
	min = is_min(stack_a);
	if ((*stack_a)->data == min)
		pb(stack_a, stack_b);
	else
	{
		while ((*stack_a)->data != min)
			ra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}

void	select_hc(int size, t_node **stack_a)
{
	t_node	*stack_b;

	stack_b = NULL;
	if (size >= 2)
	{
		if (size == 2)
			sort_2(stack_a);
		else if (size == 3)
			sort_3(stack_a);
		else if (size == 4)
			sort_4(stack_a, &stack_b);
		else if (size == 5)
			sort_5(stack_a, &stack_b);
		// else 
	}
	else
		return ;
}

