/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:11:24 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/19 21:34:20 by unovo-ru         ###   ########.fr       */
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



// // ...existing code...
// #include <limits.h>

// static t_node	*min_index_node(t_node *a)
// {
// 	t_node *min = a;
// 	t_node *cur = a->next;

// 	while (cur != a)
// 	{
// 		if (cur->index < min->index)
// 			min = cur;
// 		cur = cur->next;
// 	}
// 	return (min);
// }

// static t_node	*target_in_a_by_index(t_node *a, int b_idx)
// {
// 	t_node *cur = a;
// 	t_node *best = NULL;

// 	do {
// 		if (cur->index > b_idx && (!best || cur->index < best->index))
// 		best = cur;
// 		cur = cur->next;
// 	} while (cur != a);
// 	if (!best)
// 		best = min_index_node(a);
// 	return best;
// }

// void	b_target_in_a(t_node **stack_a, t_node **stack_b)
// {
// 	t_node	*b_start;
// 	t_node	*b_cur;
// 	t_node	*a_target;

// 	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
// 		return ;

// 	position_node(stack_a);
// 	position_node(stack_b);

// 	b_start = *stack_b;
// 	b_cur = b_start;
// 	do {
// 		a_target = target_in_a_by_index(*stack_a, b_cur->index);
// 		b_cur->target = a_target->pos;
// 		b_cur = b_cur->next;
// 	} while (b_cur != b_start);
// }
// ...existing code...

static int	ft_min(t_node **stack_a)
{
	t_node	*aux;
	int		min;

	min = INT_MAX;
	while(1)
	{
		// printf("---------HOLAAA 3----------\n\n");
		if (aux->index < min)
			min = aux->index;
		aux = aux->next;
		if (aux == (*stack_a))
			break ;
	}
	printf("---------HOLAAA 3----------\n\n");
	return (min);
}

void	b_target_in_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*aux_a;
	t_node	*aux_b;

	position_node(stack_a);
	position_node(stack_b);
	aux_a = (*stack_a);
	aux_b = (*stack_b);
	aux_b->target = INT_MAX;
	while (1)
	{
		while (1)
		{
			if (aux_a->prev->index < aux_b->index && aux_a->next->index > aux_b->index)
				aux_b->target = aux_a->next->index;
			aux_a = aux_a->next;
			printf("---------HOLAAA----------\n\n");
			if (aux_a == (*stack_a))
				break ;
		}
		printf("---------HOLAAA 2----------\n\n");
		aux_b->target = ft_min(stack_a);
		aux_b = aux_b->next;
		if (aux_b == (*stack_b))
			break ;
	}
}

