/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_b_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:28:41 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/23 22:08:08 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sb(t_node **stack_b)
{
	if (stack_b)
		swap(stack_b);
	else
		return ;
}

void	rb(t_node **stack_b)
{
	if (!*stack_b || !stack_b || (*stack_b)->next == (*stack_b))
		return ;
	rotate(stack_b);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
}

void	rrb(t_node **stack_b)
{
	reverse_rotate(stack_b);
}
