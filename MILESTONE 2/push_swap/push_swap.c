/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:01:44 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/06 18:28:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*push_swap(char **str)
{
	int		size;
	char	*final_argument;
	int		*res;
	t_node	*stack = NULL;
	// t_node	*stack_b = NULL;

	final_argument = arg_join(str);
	if (!final_argument)
		free(final_argument);
	res = get_imput(final_argument);
	if (!res || !no_empty_arg(str))
	{
		free(res);
		free(final_argument);
		print_error();
	}
	size = count_array(final_argument);
	if (is_correct(res, size) == 1)
	{
		stack = node_aplication(res, size);
		index_node(&stack, size);
		position_node(stack);
		select_hc(size, &stack);
		// printf("\t------STACK A------\n");
		// print_node((stack));
		// printf("\t------STACK B------\n");
		// print_node((stack_b));
	}
	else
		free(res);
	free(final_argument);
	return (stack);
}


/*necesito esta funcion para calcular el size del stack siempre*/

// int	get_stack_size(t_stack	*stack)
// {
// 	int	size;

// 	size = 0;
// 	if (!stack)
// 		return (0);
// 	while (stack)
// 	{
// 		stack = stack->next;
// 		size++;
// 	}
// 	return (size);
// }







		// print_node(stack);
		// printf("\t------STACK A------\n");
		// // printf("\t------STACK A------\n");
		// // select_hc(size, &stack);
		// // printf("####### STACK A #######");
		// // print_node(stack);
		// // printf("####### STACK B #######");
		// // print_node(stack_b);

