/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:26:16 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/23 21:57:38 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	stack_size(t_node **stack)
{
	int		count;
	t_node	*aux;

	count = 0;
	if (!*stack)
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

void	ft_free_stacks(t_node **stack_a, t_node **stack_b)
{
	free_nodes(stack_a);
	free_nodes(stack_b);
	print_error();
}
