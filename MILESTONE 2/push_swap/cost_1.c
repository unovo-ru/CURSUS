/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 16:19:18 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/22 14:14:21 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
	if (size <= 0)
		return (0);
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

// static t_node	*find_target(int target, t_node **stack_a)
// {
// 	t_node	*aux;

// 	aux = (*stack_a);
// 	while (1)
// 	{
// 		if (aux->target == target)
// 			return (aux);
// 		aux = aux->next;
// 		if (aux == (*stack_a))
// 			break ;
// 	}
// 	return (NULL);
// }

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
	// printf("\t------STACK A------\n");
	// print_node((*stack_a));
	// printf("\t------STACK B------\n");
	// print_node((*stack_b));
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
	// t_node	*current;

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

void	this_is_the_way(t_node **stack_a, t_node **stack_b, t_node **cheapest)
{
	if ((*cheapest)->cost_a < 0 && (*cheapest)->cost_b < 0)
	{
		rrr(stack_a, stack_b);
		(*cheapest)->cost_a++;
		(*cheapest)->cost_b++;
		(*cheapest)->total_cost -= 2;
	}
	else if ((*cheapest)->cost_a > 0 && (*cheapest)->cost_b > 0)
	{
		rr(stack_a, stack_b);
		(*cheapest)->cost_a--;
		(*cheapest)->cost_b--;
		(*cheapest)->total_cost -= 2;
	}
	else if ((*cheapest)->cost_a < 0)
	{
		rra(stack_a);
		(*cheapest)->cost_a++;
		(*cheapest)->total_cost--;
	}
	else if ((*cheapest)->cost_a > 0)
	{
		ra(stack_a);
		(*cheapest)->cost_a--;
		(*cheapest)->total_cost--;
	}
	else if ((*cheapest)->cost_b < 0)
	{
		rrb(stack_b);
		(*cheapest)->cost_b++;
		(*cheapest)->total_cost--;
	}
	else if ((*cheapest)->cost_b > 0)
	{
		rb(stack_b);
		(*cheapest)->cost_b--;
		(*cheapest)->total_cost--;
	}
}

void	heavy_bucle(t_node **stack_a, t_node **stack_b)
{
	t_node	*cheapest;

	while (*stack_b)
	{
		b_target_in_a(stack_a, stack_b);
		cost_both(stack_a, stack_b);
		total_cost(stack_b);
		cheapest = take_cheapest(stack_b);
		// printf("\t------STACK A------\n");
		// print_node((*stack_a));
		// printf("\t------STACK B------\n");
		// print_node((*stack_b));
		// printf("\t------CHEAPEST------\n");
		// exit (1);
		// printf("index del cheapest %d\n", cheapest->index);
		// printf("target del cheapest %d\n", cheapest->target);
		// printf("coste a del cheapest %d\n", cheapest->cost_a);
		// printf("coste b del cheapest %d\n", cheapest->cost_b);
		while (cheapest->total_cost > 0)
			this_is_the_way(stack_a, stack_b, &cheapest);
		if (cheapest->total_cost == 0)
			pa(stack_b, stack_a);
		// b_target_in_a(stack_a, stack_b);
	}
}
