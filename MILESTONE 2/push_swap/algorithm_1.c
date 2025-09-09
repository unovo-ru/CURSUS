/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:54:13 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/09 15:08:19 by unovo-ru         ###   ########.fr       */
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

// int	is_correct(t_node *stack_a)
// {
// 	t_node	*aux;

// 	aux = stack_a;
// 	printf("este es el stack_a [ %d ]\n", stack_a->data);
// 	printf("este es el stack_a->next [ %d ]\n", stack_a->next->data);
// 	while (stack_a->next != aux)
// 	{
// 		if ((stack_a->data) < (stack_a->next->data))
// 		{
// 			free(aux);
// 			return (0);
// 		}
// 		stack_a = stack_a->next;
// 	}
// 	return (1);
// }

int	is_correct(int *array_ints, int size)
{
	int	i;

	i = 0;
	// printf("este es el stack_a [ %d ]\n", array_ints[i]);
	// printf("este es el stack_a->next [ %d ]\n",  array_ints[i + 1]);
	while (i < size - 1)
	{
		if (array_ints[i] > array_ints[i + 1])
		{
			// printf("este es el valor de i [ %d ]\n", array_ints[i + 1]);
			// printf("este es el valor de i [ %d ]\n", array_ints[i + 2]);
			// printf("este es el valor de i [ %d ]\n", array_ints[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

void	sort_2(t_node **stack_a)
{
	ra(stack_a);
}

void	sort_3(t_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->data;
	b = (*stack_a)->next->data;
	c = (*stack_a)->next->next->data;
	if (a < b && b > c && a < c)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
	else if (a > b && b > c && a > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a > b && b < c && a < c)
		sa(stack_a);
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
	// printf("este es el menor [ %d ]\n\n", n);
	return (n);
}

/*int	is_min(t_node **stack_a)
{
	int		n;
	t_node	*aux;

	aux = (*stack_a);
	n = (*stack_a)->data;
	while ((*stack_a)->next != aux)
	{
		if (n > (*stack_a)->next->data)
			n = (*stack_a)->next->data;
		(*stack_a) = (*stack_a)->next;
	}
	printf("este es el menor [ %d ]\n\n", n);
	return (n);
}*/
