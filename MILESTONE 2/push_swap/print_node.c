/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:14:51 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/08/30 21:19:04 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node(t_node *node)
{
	printf("DATA --> %d", node->data);
	printf("INDEX --> %d", node->index);
	printf("COST --> %d", node->cost);
	printf("PREV --> %d", node->prev->data);
	printf("NEXT --> %d", node->next->data);
	//printf("HEAD --> %d", node->data);
}
