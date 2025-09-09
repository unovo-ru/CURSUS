/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:29:37 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/09 18:10:38 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_node **stack_a, t_node **stack_b)
{
	int		min;
	// int		i;
	// t_node	*tmp;

	// tmp = *stack_a;
	// i = 0;
	min = is_min(stack_a);
	while ((*stack_a)->data != min)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}

/*void	sort_5(t_node **stack_a, t_node **stack_b)
{
	t_node	*aux;
	int		n;
	int		out;

	out = 0;
	aux = (*stack_a);
	while ((*stack_a)->data != aux->data)
	{
		n = is_min(stack_a);
		if ((*stack_a)->data == n)
		{
			pa(stack_a, stack_b);
			out++;
		}
		if (out == 2)
			break ;
	}
	sort_3(stack_a);
	pb(stack_b, stack_a);
}*/
void	sort_4(t_node **stack_a, t_node **stack_b)
{
	int		min;
	//int		i;
	//t_node	*tmp;

	//tmp = *stack_a;
	// i = 0;
	min = is_min(stack_a);
	while ((*stack_a)->data != min)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_b, stack_a);
}
/*void	sort_4(t_node **stack_a, t_node **stack_b)
{
	t_node	*aux;
	int		n;
	int		out;

	out = 0;
	aux = (*stack_a);
	while ((*stack_a)->data != aux->data)
	{
		n = is_min(stack_a);
		if ((*stack_a)->data == n)
		{
			pa(stack_a, stack_b);
			out++;
		}
		if (out == 1)
			break ;
	}
	sort_3(stack_a);
	pb(stack_b, stack_a);
}*/

/*OJO, SI CREO EN ESTA FUNCION EL STACK B PUEDED ENTRAR EN COFLICTO CON OTROS
SITIOS DONDE TAMBIEN LO CREO

(NO DEBERIA PORQUE AQUI LO CREO SOLO PARA ESTOS CASOS)
*/

// void	select_hc(int size, t_node **stack_a)
// {
// 	t_node	**stack_b;

// 	stack_b = NULL;
// 	if (size <= 5)
// 	{
// 		if (size == 2)
// 		{
// 			printf("sort_2\n\n");
// 			sort_2(stack_a);
// 		}
// 		else if (size == 3)
// 		{
// 			printf("sort_3\n\n");
// 			sort_3(stack_a);
// 		}
// 		else if (size == 4)
// 		{
// 			printf("sort_4\n\n");
// 			sort_4(stack_a, stack_a);
// 		}
// 		else if (size == 5)
// 		{
// 			printf("sort_5\n\n");
// 			sort_5(stack_a, stack_b);
// 		}
// 	}
// 	else
// 		return ;
// }

void	select_hc(int size, t_node **stack_a)
{
	t_node	**stack_b;

	stack_b = NULL;
	if (size <= 5)
	{
		if (size == 2)
		{
			printf("sort_2\n\n");
			sort_2(stack_a);
		}
		else if (size == 3)
		{
			printf("sort_3\n\n");
			sort_3(stack_a);
		}
		else if (size == 4)
		{
			printf("sort_4\n\n");
			sort_4(stack_a, stack_a);
		}
		else if (size == 5)
		{
			printf("sort_5\n\n");
			sort_5(stack_a, stack_b);
		}
	}
	else
		return ;
}
