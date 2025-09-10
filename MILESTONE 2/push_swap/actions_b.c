/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:28:41 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/10 18:36:09 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_node **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	pb(t_node **stack_b, t_node **stack_a)
{
	/*tengo que ser capaz de mandar nodos a A y que B se quede vacio*/
	if ((*stack_b)->next == (*stack_b))
	{
		push(stack_b, stack_a);
		ft_printf("pb\n");
		printf("un elemento\n\n");
		*stack_b = NULL;
	}
	else
	{
		push(stack_b, stack_a);
		printf("mas de un elemento\n\n");
		ft_printf("pb\n");
	}
}

void	rrb(t_node **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}
