/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:19:18 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/17 20:51:40 by unovo-ru         ###   ########.fr       */
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
			(*stack) = (*stack)->next;
			count++;
			if ((*stack) == aux)
				break ;
		}
	}
	return (count);
}

void	pos_and_cost_a(t_node **stack)
{
	int		size;
	int		half_size;
	int		position;
	t_node	*aux;

	size = stack_size(stack);
	half_size = size / 2 + (size % 2);
	aux = (*stack);
	position = 0;
	while (1)
	{
		aux->pos = position;
		if (position <= half_size)
			aux->cost_a = position;
		else
			aux->cost_a = (size - position -1);
		aux = aux->next;
		if (aux == (*stack))
			break ;
		position++;
	}
}

void	pos_and_cost_b(t_node **stack)
{
	int		size;
	int		half_size;
	int		position;
	t_node	*aux;

	size = stack_size(stack);
	half_size = size / 2 + (size % 2);
	aux = (*stack);
	position = 0;
	while (1)
	{
		aux->pos = position;
		if (position <= half_size)
			aux->cost_a = position;
		else
			aux->cost_a = size - position * (-1);
		aux = aux->next;
		if (aux == (*stack))
			break ;
		position++;
	}
}

void	cost_both(t_node **stack_a, t_node **stack_b)
{
	pos_and_cost_a(stack_a);
	pos_and_cost_b(stack_b);
}

