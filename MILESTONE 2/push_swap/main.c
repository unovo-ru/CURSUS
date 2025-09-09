/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:59:20 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/06 18:34:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	(void)argc;
	t_node *stack_a = NULL;
	t_node *stack_b = NULL;

	// int i = 0;
	// int *res = final_input(argv);
	// if (!res)
	// 	print_error();
	// printf("llega\n\n");
	// node_aplication(argv, res);
	// while (i < 4)
	// {
	// 	printf("esto es mi imput = %d\n\n", res[i]);
	// 	i++;
	// }
	// stack_a = node_aplication(argv, res);
	stack_a = push_swap(argv);
	// is_min(&stack_a);
	// printf("\t------STACK A------\n");
	// print_node(stack_a);
	// printf("\t------STACK B------\n");
	// print_node(stack_b);

	// if(!is_correct(stack_a))
	// {
		// printf("-----------antes de rotar-------\n");
		// printf("\t------STACK A------\n");
		// print_node(stack_a);
	// }
	// printf("\t------STACK B------\n");
	// print_node(stack_b);
	// printf("-----------después de rotar-------\n");
	// reverse_rotate(&stack_a);
	// push(&stack_a, &stack_b);
	// push(&stack_a, &stack_b);
	// print_node(stack_a);
	// printf("\t------STACK B------\n");
	// print_node(stack_b);


//	printf("--------PRUEBA DE MOVIMIENTO-------\n");
	//sa sb ss
//	printf("\t------STACK A------\n");
//	ss(&stack_a, &stack_b);
//	sa(&stack_a);
//	print_node(stack_a);
//	sb(&stack_b);
//	printf("\t------STACK B------\n");
//	print_node(stack_b);


	//ra rb rr
//	printf("--------PRUEBA DE MOVIMIENTO-------\n");
//	rr(&stack_a, &stack_b);
//	printf("\t------STACK A------\n");
//	ra(&stack_a);
//	print_node(stack_a);
//	printf("\t------STACK B------\n");
//	rb(&stack_b);
//	print_node(stack_b);

//pa pb

//	printf("--------PRUEBA DE MOVIMIENTO-------\n");

//rra rrb rrr
//	rrr(&stack_a, &stack_b);
//	rra(&stack_a);
//	print_node(stack_a);

//	rrb(&stack_b);
//	print_node(stack_b);

//	rrr(&stack_a, &stack_b);


	//printf("\t------STACK A------\n");
	//print_node(stack_a);
	//printf("\t------STACK B------\n");
	//print_node(stack_b);
	//printf("tamaño del stack %d\n", ft_node_size(stack_a));

	free_nodes(&stack_a); /* POR QUE DA ERROR LIBERAR EL NODO A?*/
	free_nodes(&stack_b);
	return (0);
}















	/*char *av = arg_join(&(*argv));
	if (!av)
		return (0);
	if (argc == 1)
		return (0);
	if (!no_empty_arg(argv))
	{
		free(av);
		print_error();
	}
	else
		printf("esto son mis args unidos --> %s\n\n", av);
	int *array = get_imput(av);
	if (!array)
		free(av);
	while (i < 5)
	{
		printf("esto es mi imput = %d\n", array[i]);
		i++;
	}
	free(array);
	free(av);
	return (0);
}*/
