/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:54:13 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/19 13:15:59 by unovo-ru         ###   ########.fr       */
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
	// t_node	*cheapest;

	count = size;
	printf("Size: %d\n", size);
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
	// b_target_in_a(stack_a, stack_b);
	// position_node(stack_a);
	// position_node(stack_b);
	// cost_both(stack_a, stack_b);
	// total_cost(stack_b);
	// cheapest = take_cheapest(stack_b);
	printf("\t------STACK A------\n");
	print_node((*stack_a));
	printf("\t------STACK B------\n");
	print_node((*stack_b));
	printf("\t------CHEAPEST------\n");
	// print_node(cheapest);
}







// void	position_node(t_node **stack)
// {
// 	t_node	*aux;
// 	int		i;

// 	i = 1;
// 	aux = (*stack);
// 	while (1)
// 	{
// 		aux->pos = i;
// 		aux = aux->next;
// 		i++;
// 		if (aux == (*stack))
// 			break ;
// 	}
// }


/*no necesito estas 2 funciones*/

/*void	push_minor_to_b(t_node **stack_a, t_node **stack_b)
{
	int	min;

	while (ft_node_size(stack_a) > 3)
	{
		min = is_min(stack_a);
		if (is_min_in_mid(stack_a) == 1)
		{
			while ((*stack_a)->data != min)
				ra(stack_a);
			pb(stack_a, stack_b);
		}
		else
		{
			while ((*stack_a)->data != min)
				rra(stack_a);
			pb(stack_a, stack_b);
		}
	}
	sort_3(stack_a);
	while (ft_node_size(stack_b) > 1)
		pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}

int	is_min_in_mid(t_node **stack_a)
{
	int		min;
	int		size_node;
	int		count;
	t_node	*tmp;

	tmp = *stack_a;
	min = is_min(stack_a);
	size_node = ft_node_size(stack_a) / 2;
	count = 0;
	while (count < size_node)
	{
		tmp = tmp->next;
		count++;
		if (tmp->data == min)
			return (1);
	}
	return (0);

}*/
