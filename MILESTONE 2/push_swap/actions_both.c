/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_both.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:31:30 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/03 19:39:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(&(*stack_a));
	swap(&(*stack_b));
	ft_printf("ss\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(&(*stack_a));
	rotate(&(*stack_b));
	ft_printf("rr\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate(&(*stack_a));
	reverse_rotate(&(*stack_b));
	ft_printf("rrr\n");
}
