/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:03:25 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/25 13:51:43 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*this function fits every number in a node*/

t_node	*ft_new_node(int data)
{
	t_node	*aux;

	aux = malloc(sizeof(t_node));
	if (!aux)
		return (NULL);
	aux->index = -1;
	aux->pos = -1;
	aux->cost_a = 0;
	aux->cost_b = 0;
	aux->total_cost = 0;
	aux->target = -1;
	aux->data = data;
	aux->prev = aux;
	aux->next = aux;
	return (aux);
}

void	ft_node_add_back(t_node **head, t_node *new_node)
{
	if (!new_node || !head)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	(*head)->prev->next = new_node;
	new_node->next = (*head);
	new_node->prev = (*head)->prev;
	(*head)->prev = new_node;
}
