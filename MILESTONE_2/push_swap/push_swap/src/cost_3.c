/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:09:51 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/23 13:06:20 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rr(t_node **stack_a, t_node **stack_b, t_node **cheapest)
{
	rr(stack_a, stack_b);
	(*cheapest)->cost_a--;
	(*cheapest)->cost_b--;
	(*cheapest)->total_cost -= 2;
}

void	do_rra(t_node **stack_a, t_node **cheapest)
{
	rra(stack_a);
	(*cheapest)->cost_a++;
	(*cheapest)->total_cost--;
}

void	do_ra(t_node **stack_a, t_node **cheapest)
{
	ra(stack_a);
	(*cheapest)->cost_a--;
	(*cheapest)->total_cost--;
}

void	do_rrb(t_node **stack_b, t_node **cheapest)
{
	rrb(stack_b);
	(*cheapest)->cost_b++;
	(*cheapest)->total_cost--;
}

void	do_rb(t_node **stack_b, t_node **cheapest)
{
	rb(stack_b);
	(*cheapest)->cost_b--;
	(*cheapest)->total_cost--;
}
