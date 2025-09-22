/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:29:41 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/22 14:58:08 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	position_node(t_node **stack_a)
{
	t_node	*aux;
	int		i;

	aux = *stack_a;
	i = 0;
	while (1)
	{
		aux->pos = i;
		aux = aux->next;
		i++;
		if (aux == (*stack_a))
			return ;
	}
}

void	index_node(t_node **stack_a, int size)
{
	int		min;
	int		i;
	t_node	*aux;

	i = 1;
	aux = *stack_a;
	while (i < size + 1)
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
