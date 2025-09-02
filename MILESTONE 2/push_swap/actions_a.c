/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:20:41 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/02 14:58:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node *stack_a)
{
	swap(&stack_a);
	ft_printf("sa\n");
}

void	ra(t_node *stack_a)
{
	rotate(&stack_a);
	ft_printf("ra\n");
}

void	pa(t_node *stack_a, t_node *stack_b)
{
	push(&stack_a, &stack_b);
	ft_printf("pa\n");
}

void	rra(t_node *stack_a)
{
	reverse_rotate(&stack_a);
	ft_printf("rra\n");
}
