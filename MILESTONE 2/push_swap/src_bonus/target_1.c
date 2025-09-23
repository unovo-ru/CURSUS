/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:11:24 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/23 13:04:04 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node **stack)
{
	int		count;
	t_node	*aux;

	count = 0;
	if (!stack)
		return (0);
	aux = *stack;
	while (1)
	{
		aux = aux->next;
		count++;
		if (aux == (*stack))
			break ;
	}
	return (count);
}

int	min_pos_aux(int n, t_node *aux, t_node *current)
{
	current = aux;
	while (1)
	{
		if (current->pos < 0 && current->data < n)
			n = current->data;
		current = current->next;
		if (current == aux)
			break ;
	}
	return (n);
}

int	is_min_pos(t_node **stack_a)
{
	int		n;
	t_node	*aux;
	t_node	*current;

	aux = (*stack_a);
	current = aux;
	while (1)
	{
		if (current->pos < 0)
		{
			n = current->data;
			break ;
		}
		current = current->next;
		if (current == aux)
			break ;
	}
	current = aux->next;
	n = min_pos_aux(n, aux, current);
	return (n);
}

void	b_target_in_a(t_node **stack_a, t_node **stack_b, t_node *tmp)
{
	t_node	*aux_a;
	t_node	*aux_b;

	aux_a = (*stack_a);
	aux_b = (*stack_b);
	while (1)
	{
		tmp = NULL;
		while (1)
		{
			if (aux_a->index > aux_b->index && (tmp == NULL
					|| tmp->index > aux_a->index))
				tmp = aux_a;
			aux_a = aux_a->next;
			if (aux_a == (*stack_a))
				break ;
		}
		if (tmp)
			aux_b->target = tmp->pos;
		else
			aux_b->target = is_min_pos(stack_a);
		aux_b = aux_b->next;
		if (aux_b == (*stack_b))
			break ;
	}
}
