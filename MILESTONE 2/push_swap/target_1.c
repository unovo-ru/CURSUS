/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:11:24 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/19 11:57:10 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node **stack)
{
	int		count;
	t_node	*aux;

	count = 0;
	aux = *stack;
	if (stack == 0)
		return (0);
	else
	{
		while (1)
		{
			aux = aux->next;
			count++;
			if (aux == (*stack))
				break ;
		}
	}
	return (count);
}

void	b_target_in_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*aux_a;
	t_node	*aux_b;

	position_node(stack_a);
	position_node(stack_b);
	aux_a = (*stack_a);
	aux_b = (*stack_b);
	while (1)
	{
		while (1)
		{
			// aux_a = aux_a->next;
			// printf("A target: %d, a po: %d\n", aux_a->target, aux_a->pos);
			if (aux_b->index < aux_a->index)
				aux_b->target = aux_a->pos;
			if (aux_a == (*stack_a))
				break ;
			aux_a = aux_a->next;
		}
		aux_b = aux_b->next;
		if (aux_b == (*stack_b))
			break ;
	}
}

