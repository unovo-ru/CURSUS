/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit_num_in_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:45:09 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/02 19:50:18 by marvin           ###   ########.fr       */
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

/*AQUI TENGO EL SEGFAULT!!!!!!!!!!*/

t_node	*node_aplication(char **str, int *num_array, int size)
{
	int		i;
	t_node	*head;
	t_node	*new_node;

	i = 0;
	head = ft_new_node(num_array[i]);
	i++;
	size = count_array(str);
	//printf("contenido de mi head --> [ %d ]\n\n", head->data);
	//print_node(head);
	while (i < size - 1)
	{
		new_node = ft_new_node(num_array[i]);
		ft_node_add_back(&head, new_node);
		if (!new_node)
			free(new_node);
		//print_node(new_node);
		i++;
	}
	//printf("-----------esto es el head -------");
	//print_node(head);
	return (head);
}



t_node	*create_b_stack(void)
{
	t_node	*stack_b;

	stack_b = ft_new_node(0);
	return (stack_b);
}
