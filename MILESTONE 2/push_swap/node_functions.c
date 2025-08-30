/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:03:25 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/08/13 18:05:39 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* funciones que necesitare en los utils

	ft_lstnew *
	ft_lst_add_back *
	ft_lstlast *

*/

#include "push_swap.h"

t_node	*ft_new_node(int data)
{
	t_node	*aux;

	aux = malloc(sizeof(t_node));
	if (!aux)
		return (NULL);
	ft_memset(aux, 0, sizeof(t_node));
	aux->data = data;
	return (aux);
}

void	ft_add_node_back(t_node **lst, t_node *new)
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
}

t_node	*ft_last_node(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

