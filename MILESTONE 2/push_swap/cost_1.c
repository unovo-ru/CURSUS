/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:19:18 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/22 15:00:20 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost(t_node **stack, int position)
{
	int		size;
	int		cost;

	size = stack_size(stack);
	if (size <= 0)
		return (0);
	cost = 0;

	if (position > size / 2)
		cost = (-1) * (size - position);
	else
		cost = position;
	return (cost);
}

void	cost_both(t_node **stack_a, t_node **stack_b)
{
	t_node	*aux_b;
	t_node	*aux_a;

	aux_a = (*stack_a);
	aux_b = (*stack_b);
	while (1)
	{
		aux_b->cost_a = cost(&aux_a, aux_b->target);
		aux_b->cost_b = cost(&aux_b, aux_b->pos);
		aux_b = aux_b->next;
		if (aux_b == (*stack_b))
			break ;
	}
}

int	abs_cost(int nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	return (nbr);
}

void	total_cost(t_node **stack_b)
{
	t_node	*aux_b;

	aux_b = (*stack_b);
	while (1)
	{
		aux_b->total_cost = abs_cost(aux_b->cost_a) + abs_cost(aux_b->cost_b);
		aux_b = aux_b->next;
		if (aux_b == (*stack_b))
			break ;
	}
}

t_node	*take_cheapest(t_node **stack)
{
	int		min_cost;
	t_node	*aux;
	t_node	*cheapest;

	aux = *stack;
	cheapest = aux;
	min_cost = aux->total_cost;
	aux = aux->next;
	while (aux != (*stack))
	{
		if (min_cost > aux->total_cost)
		{
			min_cost = aux->total_cost;
			cheapest = aux;
		}
		aux = aux->next;
	}
	return (cheapest);
}
