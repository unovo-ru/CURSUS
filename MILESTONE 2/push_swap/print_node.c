/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:14:51 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/01 14:11:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node(t_node *node)
{
	printf("---------------------------\n\n");
	printf("DATA --> [ %d ]\n", node->data);
	//printf("INDEX --> [ %d ]\n", node->index);
	//printf("COST --> [ %d ]\n", node->cost);
	printf("PREV --> [ %d ]\n", node->prev->data);
	printf("NEXT --> [ %d ]\n", node->next->data);
	printf("---------------------------\n\n");
}
