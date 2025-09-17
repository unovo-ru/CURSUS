/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:11:24 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/17 17:16:48 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_node(t_node **stack_a, t_node **stack_b)
{
	
}

t_node	*find_min_index(t_node **stack)
{
	t_node	*aux;
	t_node	*current;

	aux = (*stack);
	current = (*stack)->next;
	while (1)
	{
		if (current->index < aux->index)
			aux = current;
		current = current->next;
		if (current == stack)
			break ;
	}
	return (aux);
}

t_node	*target_a(t_node **stack_a, int )