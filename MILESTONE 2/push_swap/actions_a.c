/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:20:41 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/22 14:57:12 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a)
{
	swap(&(*stack_a));
	ft_printf("sa\n");
}

void	ra(t_node **stack_a)
{
	if (!*stack_a || !stack_a || (*stack_a)->next == (*stack_a))
		return ;
	rotate(&(*stack_a));
	ft_printf("ra\n");
}

void	pa(t_node **stack_b, t_node **stack_a)
{
	if ((*stack_b)->next == (*stack_b))
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
		*stack_b = NULL;
	}
	else
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
	}
}

void	rra(t_node **stack_a)
{
	reverse_rotate(&(*stack_a));
	ft_printf("rra\n");
}
