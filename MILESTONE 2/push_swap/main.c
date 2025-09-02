/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:59:20 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/02 20:04:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	(void)argc;
	t_node *stack_a;
	t_node *stack_b = create_b_stack();

	//int i = 0;
	int *res = final_input(argv);
	int count = count_array(&argv[1]);
	//printf("esto es el size --> %d\n\n", count);
	if (!res)
		print_error();
	//printf("llega\n\n");
	//node_aplication(argv, res, count - 1);
	//while (i < count)
	//{
	//	printf("esto es mi imput = %d\n\n", res[i]);
	//	i++;
	//}
	stack_a = node_aplication(argv, res, count);
	printf("-----------antes de rotar-------\n");
	printf("\t------STACK A------\n");
	print_node(stack_a);
	printf("\t------STACK B------\n");
	print_node(stack_b);
	printf("-----------después de rotar-------\n");
	//reverse_rotate(&stack_a);
	push(&stack_a, &stack_b);
	printf("\t------STACK A------\n");
	print_node(stack_a);
	printf("\t------STACK B------\n");
	print_node(stack_b);
	//printf("tamaño del stack %d\n", ft_node_size(stack_a));
	free(res);
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
