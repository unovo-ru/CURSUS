/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:14:51 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/23 13:06:43 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node(t_node *node)
{
	t_node	*aux;

	aux = node;
	if (!node)
	{
		printf("(stack vacío)\n");
		return ;
	}
	while (1)
	{
		printf("---------------------------\n\n");
		printf("DATA --> [ %d ]\n", aux->data);
		printf("INDEX --> [ %d ]\n", aux->index);
		printf("COST A--> [ %d ]\n", aux->cost_a);
		printf("COST B--> [ %d ]\n", aux->cost_b);
		printf("TOTAL COST --> [ %d ]\n", aux->total_cost);
		printf("TARGET --> [ %d ]\n", aux->target);
		printf("POS --> [ %d ]\n", aux->pos);
		printf("PREV --> [ %d ]\n", aux->prev->data);
		printf("NEXT --> [ %d ]\n", aux->next->data);
		printf("---------------------------\n\n");
		aux = aux->next;
		if (aux == node)
			break ;
	}
}

