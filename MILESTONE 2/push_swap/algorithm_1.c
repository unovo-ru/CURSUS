/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:54:13 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/22 14:35:53 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*this function selects which the algorithm*/

void	select_hc(int size, t_node **stack_a)
{
	t_node	*stack_b;

	stack_b = NULL;
	if (size >= 2)
	{
		if (size == 2)
			sort_2(stack_a);
		else if (size == 3)
			sort_3(stack_a);
		else if (size == 4)
			sort_4(stack_a, &stack_b);
		else if (size == 5)
			sort_5(stack_a, &stack_b);
		else
			sort_stack(stack_a, &stack_b, size);
	}
	else
		return ;
	free_nodes(&stack_b);
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
	current = aux;
	while (1)
	{
		if (current->index < 0)
		{
			n = current->data;
			break ;
		}
		current = current->next;
		if (current == aux)
			break ;
	}
	current = aux->next;
	n = min_aux(n, aux, current);
	return (n);
}

int	min_aux(int n, t_node *aux, t_node *current)
{
	current = aux;
	while (1)
	{
		if (current->index < 0 && current->data < n)
			n = current->data;
		current = current->next;
		if (current == aux)
			break ;
	}
	return (n);
}

void	sort_stack(t_node **stack_a, t_node **stack_b, int size)
{
	int	count;

	count = size;
	while (count)
	{
		if ((*stack_a)->index < size / 2 + (size % 2))
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		count--;
	}
	while (1)
	{
		if (stack_size(stack_a) == 3)
			break ;
		if ((*stack_a)->index < size - 2)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_3(stack_a);
	heavy_bucle(stack_a, stack_b);

}
