/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:14:51 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/01 17:18:30 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node(t_node *node)
{
	t_node	*aux;

	aux = node;
	while (1)
	{
		printf("---------------------------\n\n");
		printf("DATA --> [ %d ]\n", aux->data);
		//printf("INDEX --> [ %d ]\n", aux->index);
		//printf("COST --> [ %d ]\n", aux->cost);
		printf("PREV --> [ %d ]\n", aux->prev->data);
		printf("NEXT --> [ %d ]\n", aux->next->data);
		printf("---------------------------\n\n");
		aux = aux->next;
		if (aux == node)
			break ;
	}
}

