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
	t_node	*stack;

	final_argument = arg_join(str);
	if (!final_argument)
		free(final_argument);
	res = get_imput(final_argument);
	//free(final_argument);
	if (!res || !no_empty_arg(str))
	{
		free(res);
		free(final_argument);
		print_error();
	}
	size = count_array(final_argument);
	stack = node_aplication(res, size);
	printf("este es el input final = %s\n", final_argument);
	printf("este es el size = %d\n", size);
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
