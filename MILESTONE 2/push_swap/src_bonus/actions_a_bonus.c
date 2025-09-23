/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_a_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:59:48 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/23 20:48:36 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_node **stack_a)
{
	swap(&(*stack_a));
}

void	ra(t_node **stack_a)
{
	if (!*stack_a || !stack_a || (*stack_a)->next == (*stack_a))
		return ;
	rotate(stack_a);
}

void	pa(t_node **stack_b, t_node **stack_a)
{
	if ((*stack_b)->next == (*stack_b))
	{
		push(stack_b, stack_a);
		*stack_b = NULL;
	}
	else
	{
		push(stack_b, stack_a);
	}
}

void	rra(t_node **stack_a)
{
	reverse_rotate(stack_a);
}
