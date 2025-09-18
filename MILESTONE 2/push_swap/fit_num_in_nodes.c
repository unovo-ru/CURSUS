/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit_num_in_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 16:45:09 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/18 15:33:33 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*this function counts how many inst i have in my array*/

int	count_array(char *array_ints)
{
	int		count;
	char	**array;

	array = ft_split(array_ints, ' ');
	count = 0;
	while (array[count])
		count++;
	free_array(array);
	return (count);
}

/*this function calls every function about nodes*/


/*!!!!!!!!!!!!!!!!!IF THIS CASE IS UNIVERSAL I MAY
			HAVE TO HARDCODE OTHER CASES
LIKE WHEN I HAVE ONLY 3-4 NUMBERS!!!!!!!!!!!!!!!!*/

/*AQUI TENGO EL SEGFAULT!!!!!!!!!!*/

t_node	*node_aplication(int *num_array, int size)
{
	int		i;
	t_node	*head;
	t_node	*new_node;

	i = 1;
	head = ft_new_node(num_array[0]);
	if (!head)
	{
		free(num_array);
		free(head);
		return (NULL);
	}
	while (i < size)
	{
		new_node = ft_new_node(num_array[i]);
		ft_node_add_back(&head, new_node);
		if (!new_node)
		{
			free(num_array);
			return (NULL);
		}
		i++;
	}
	free(num_array);
	return (head);
}

t_node	*create_b_stack(void)
{
	t_node	*stack_b;

	stack_b = ft_new_node(0);
	return (stack_b);
}

void	free_nodes(t_node **node)
{
	t_node	*current;
	t_node	*next;

	current = (*node);
	if (!current)
		return ;
	while (1)
	{
		next = current->next;
		free(current);
		current = next;
		if (current == (*node))
			break ;
	}
}
