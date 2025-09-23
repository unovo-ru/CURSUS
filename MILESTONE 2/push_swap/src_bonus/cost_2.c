/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:00:30 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/23 13:04:34 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rrr(t_node **stack_a, t_node **stack_b, t_node **cheapest)
{
	rrr(stack_a, stack_b);
	(*cheapest)->cost_a++;
	(*cheapest)->cost_b++;
	(*cheapest)->total_cost -= 2;
}

void	this_is_the_way(t_node **stack_a, t_node **stack_b, t_node **cheapest)
{
	if ((*cheapest)->cost_a < 0 && (*cheapest)->cost_b < 0)
		do_rrr(stack_a, stack_b, cheapest);
	else if ((*cheapest)->cost_a > 0 && (*cheapest)->cost_b > 0)
		do_rr(stack_a, stack_b, cheapest);
	else if ((*cheapest)->cost_a < 0)
		do_rra(stack_a, cheapest);
	else if ((*cheapest)->cost_a > 0)
		do_ra(stack_a, cheapest);
	else if ((*cheapest)->cost_b < 0)
		do_rrb(stack_b, cheapest);
	else if ((*cheapest)->cost_b > 0)
		do_rb(stack_b, cheapest);
}

void	final_sort(t_node **stack)
{
	t_node	*aux;
	int		i;
	int		size;

	size = stack_size(stack);
	aux = (*stack);
	i = 0;
	while (i < size)
	{
		if (aux->index == 1)
			break ;
		aux = aux->next;
		i++;
	}
	if (i < size / 2)
	{
		while (i-- > 0)
			ra(stack);
	}
	else
		while (i++ < size)
			rra(stack);
}

void	heavy_bucle(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest;

	while (*stack_b)
	{
		position_node(stack_a);
		position_node(stack_b);
		b_target_in_a(stack_a, stack_b, NULL);
		cost_both(stack_a, stack_b);
		total_cost(stack_b);
		cheapest = take_cheapest(stack_b);
		while (cheapest->total_cost > 0)
			this_is_the_way(stack_a, stack_b, &cheapest);
		if (cheapest->total_cost == 0)
			pa(stack_b, stack_a);
	}
}
