/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:14:51 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/16 15:37:06 by marvin           ###   ########.fr       */
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
		// printf("COST --> [ %d ]\n", aux->cost);
		printf("POS --> [ %d ]\n", aux->pos);
		// printf("PREV --> [ %d ]\n", aux->prev->data);
		// printf("NEXT --> [ %d ]\n", aux->next->data);
		printf("---------------------------\n\n");
		aux = aux->next;
		if (aux == node)
			break ;
	}
}

