/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:03:25 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/02 13:46:33 by marvin           ###   ########.fr       */
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
	aux->index = 0;
	aux->cost = 0;
	aux->data = data;
	aux->prev = aux;
	aux->next = aux;
	return (aux);
}

/*this function adds a node at the end of the list*/

/*!!!!!!!		ADD THE PREVS		!!!!!!!!!!*/

/*void	add_node_back(t_node **lst, t_node *new)
{
	t_node	*a;

	if (!new || !lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	a = *lst;
	while (a->next)
		a = a->next;
	a->next = new;
}*/

/*!!!!!!!		IS IT NESSESARY????? 			!!!!!!!!!*/

t_node	*ft_last_node(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*tengo que hacer que el nodo que apunte a NULL
sea el que apunte al primero de nuevo*/

/*!!!!!!!CHECK IF IT IS RIGHT!!!!!*/

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

/*!!!!!!!CHECK IF IT IS RIGHT!!!!!*/

void	ft_front_node(t_node **node, t_node *new_node)
{
	if (!new_node || !node)
		return ;
	new_node->next = *node;
	new_node->prev = &(*new_node);
	*node = new_node;
}

/*int	ft_node_size(t_node **stack)
{
	if (stack == 0)
		return (0);
	else
		return (1 + ft_node_size(&(*stack)->next));
}*/

int	ft_node_size(t_node **stack)
{
	int	count;

	count = 0;
	if (stack == 0)
		return (0);
	else
		while (*stack)
		{
			(*stack) = (*stack)->next;
			count++;
		}
	return (count);
}
