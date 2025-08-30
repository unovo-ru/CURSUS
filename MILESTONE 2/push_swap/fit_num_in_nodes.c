/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit_num_in_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:45:09 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/08/30 22:39:23 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*this function counts how many inst i have in my array*/

int	count_array(char **array_ints)
{
	int	count;

	count = 0;
	while (array_ints[count])
		count++;
	return (count);
}

/*this function calls every function about nodes*/


/*!!!!!!!!!!!!!!!!!IF THIS CASE IS UNIVERSAL I MAY 
			HAVE TO HARDCODE OTHER CASES 
LIKE WHEN I HAVE ONLY 3-4 NUMBERS!!!!!!!!!!!!!!!!*/

t_node	*node_aplication(char **str, int *num_array, int size, t_node *new_node)
{
	int		i;
	t_node	**head;

	i = 0;
	(*head) = ft_new_node(num_array[i]);
	i++;
	size = count_array(str);
	while (i < size - 1)
	{
		ft_add_node_back(head, new_node);
		if (!new_node)
			free(new_node);
		new_node = new_node->next;
		printf("contenido de mi nodo --> [ %d ]\n", new_node->data);
		i++;
	}
	return (new_node);
}

