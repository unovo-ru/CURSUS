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
		index_node(stack);
		// print_node(stack);
		// printf("\t------STACK A------\n");
		select_hc(size, &stack);
		// printf("####### STACK A #######");
		// print_node(stack);
		// printf("####### STACK B #######");
		// print_node(stack_b);
	}
	else
		free(res);
	// if (is_correct(res, size) == 0)
	// {
	// 	printf("\n\nhola\n\n");
	// 	free(final_argument);
	// 	return (NULL);
	// }
	// else
	// {
	// 	select_hc(size, &stack);
	// 	// is_min(&stack);
	// 	// index_node(stack);
	// 	printf("\t------STACK A------\n");
	// 	print_node(stack);
	// }
	// printf("este es el input final = %s\n", final_argument);
	// printf("este es el size = %d\n", size);
	// if (!is_correct(stack))
	// {
	// 	printf("hola\n\n");
	// 	free(stack);
	// 	free(final_argument);
	// 	return (NULL);
	// }
	//else
	free(final_argument);
	return (stack);
}


/*int	main()
{

	parseo:
	1 que solo acepte numeros (caso contyrario debe saltar "ERROR")
	2 los valores han de estar acotados en MAX_INT y MIN_INT
	3 los argumentos no deben distinguir entre los que van con comillas
	o sin comillas

	push_swap();
	return (0);
}*/
