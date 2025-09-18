/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:11:24 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/18 19:17:06 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	target_node(t_node **stack_a, t_node **stack_b)
// {
	
// }

// t_node	*find_min_index(t_node **stack)
// {
	// t_node	*aux;
	// t_node	*current;
// 
	// aux = (*stack);
	// current = (*stack)->next;
	// while (1)
	// {
		// if (current->index < aux->index)
			// aux = current;
		// current = current->next;
		// if (current == stack)
			// break ;
	// }
	// return (aux);
// }

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

