/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:54:13 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/11 13:55:09 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
1.- estan ordenados salgo al volver al inicio
2.- mientras esten ordenados itero para encontrar donde no lo estan
3.-rompemos en el momento que deje de estar ordenado
*/

/*CHECK THE ORDER OF THESE 3 FUNCTIONS!!!!!!!!!*/

/*
i must manege if the input are:
- its alredy in order (1 2 3). is_correct
- 2 numbers. sort_2
- 3 numbers. sort_3
*/

void	index_node(t_node *stack_a)
{
	t_node	*aux;
	int		i;

	aux = stack_a;
	i = 1;
	while (1)
	{
		stack_a->index = i;
		stack_a = stack_a->next;
		i++;
		if (stack_a == aux)
			return ;
	}
}

int	is_correct(int *array_ints, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array_ints[i] > array_ints[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	is_min(t_node **stack_a)
{
	int		n;
	t_node	*aux;
	t_node	*current;

	aux = (*stack_a);
	n = aux->data;
	current = aux->next;
	while (current != aux)
	{
		if (n > current->data)
			n = current->data;
		current = current->next;
	}
	return (n);
}


void	push_minor_to_b(int size, t_node **stack_a, t_node **stack_b)
{
	int	min;

	while (ft_node_size(stack_a) > 3)
	{
		min = is_min(stack_a);
	}
}
