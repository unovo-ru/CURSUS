/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:03:25 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/24 16:35:14 by unovo-ru         ###   ########.fr       */
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

// t_node	*ft_last_node(t_node *lst)
// {
// 	if (!lst)
// 		return (NULL);
// 	while (lst->next)
// 		lst = lst->next;
// 	return (lst);
// }

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

/*this function adds a node at the beginning of the list*/

// void	ft_front_node(t_node **node, t_node *new_node)
// {
// 	if (!new_node || !node)
// 		return ;
// 	new_node->next = *node;
// 	new_node->prev = &(*new_node);
// 	*node = new_node;
// }
