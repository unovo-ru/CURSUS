/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:22:27 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/26 16:25:33 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_node **stack)
{
	t_node	**h;

	h = stack;
	if (!(*stack))
		return ;
	(*h)->prev->next = (*h)->next;
	(*h)->next->prev = (*h)->prev;
	(*h)->prev = (*h)->next;
	(*h)->next = (*h)->next->next;
	(*h)->prev->next = (*h);
	(*h)->next->prev = (*h);
	(*h) = (*h)->prev;
}

void	push(t_node **stack_source, t_node **stack_dest)
{
	t_node	*a;

	if (!*stack_source)
		return ;
	a = *stack_source;
	empty_dest(stack_source);
	if (!*stack_dest)
	{
		a->next = a;
		a->prev = a;
		*stack_dest = a;
	}
	else
	{
		a->next = *stack_dest;
		a->prev = (*stack_dest)->prev;
		(*stack_dest)->prev->next = a;
		(*stack_dest)->prev = a;
		*stack_dest = a;
	}
}

void	empty_dest(t_node **stack_source)
{
	t_node	*a;

	a = *stack_source;
	if (a->next == a)
		*stack_source = NULL;
	else
	{
		a->prev->next = a->next;
		a->next->prev = a->prev;
		*stack_source = a->next;
	}
}

void	rotate(t_node **stack)
{
	if (!(*stack))
		return ;
	(*stack) = (*stack)->next;
}

void	reverse_rotate(t_node **stack)
{
	if (!(*stack))
		return ;
	(*stack) = (*stack)->prev;
}
