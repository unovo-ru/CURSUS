/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:19:18 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/18 21:49:06 by unovo-ru         ###   ########.fr       */
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

// void	pos_and_cost_a(t_node **stack)
// {
// 	int		size;
// 	int		half_size;
// 	int		cost;
// 	t_node	*aux;

// 	size = stack_size(stack);
// 	half_size = size / 2 + (size % 2);
// 	aux = (*stack);
// 	cost = 0;
// 	while (1)
// 	{
// 		if (aux->pos <= half_size)
// 			aux->cost_a = aux->pos;
// 		else
// 			aux->cost_a = (size - aux->pos) * (-1);
// 		aux = aux->next;
// 		if (aux == (*stack))
// 			break ;
// 		cost++;
// 	}
// }

int	cost(t_node **stack, int position)
{
	int		size;
	// int		half_size;
	int		cost;
	// t_node	*aux;

	size = stack_size(stack);
	// half_size = size / 2;
	// aux = (*stack);
	cost = 0;

	if (position > size / 2)
		cost = (-1) * (size - position);
	else
		cost = position;
	// if (position <= half_size)
	// 	cost = aux->pos;
	// else
	// 	cost = size - position * (-1);
	return (cost);
}


void	cost_both(t_node **stack_a, t_node **stack_b)
{
	// t_node	*aux_a;
	t_node	*aux_b;

	// aux_a = (*stack_a);
	aux_b = (*stack_b);
	while (1)
	{
		aux_b->cost_a = cost(stack_a, aux_b->target);
		aux_b->cost_b = cost(stack_b, aux_b->pos);
		aux_b = aux_b->next;
		if (aux_b == (*stack_b))
			break ;
	}
	// printf("\t------STACK A------\n");
	// print_node((*stack_a));
	// printf("\t------STACK B------\n");
	// print_node((*stack_b));
}

void	total_cost(t_node **stack_b)
