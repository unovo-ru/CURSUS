/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:29:41 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/12 17:58:34 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	position_node(t_node *stack_a)
{
	t_node	*aux;
	int		i;

	aux = stack_a;
	i = 1;
	while (1)
	{
		stack_a->pos = i;
		stack_a = stack_a->next;
		i++;
		if (stack_a == aux)
			return ;
	}
}

void	index_node(t_node **stack_a, int size)
{
	int		min;
	int		i;
	t_node	*aux;

	i = 0;
	aux = *stack_a;
	while (i < size)
	{
		min = is_min(stack_a);
		if (aux->data == min && aux->index < 0)
		{
			aux->index = i;
			aux = aux->next;
			i++;
		}
		else
			aux = aux->next;
	}
}

// void	target_node(t_node **stack_a, t_node **stack_b)
// {
// 	t_node	*aux_a;
// 	t_node	*aux_b;

// 	aux_a = *stack_a;
// 	aux_b = *stack_b;
// 	while (1)
// 	{
// 		if((*stack_a)->index == (*stack_b)->index - 1)
			
// 	}
// }

int	target_b(t_node **stack_b)
{
	t_node	*aux;
	int		target;

	target = 0;
	aux = *stack_b;
	while (1)
	{
		aux = aux->next;
		if (aux == (*stack_b))
			break ;
	}
}
