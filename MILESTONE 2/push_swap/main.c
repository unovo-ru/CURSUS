/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:59:20 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/08/30 20:24:39 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	(void)argc;
	//int i = 0;
	int count = count_array(argv);
	int *res = final_input(argv);
	if (!res)
		print_error();
	node_aplication(argv, res, count - 1);
	// while (i < count - 1)
	// {
	// 	//printf("esto es mi imput = %d\n", res[i]);
	// 	node_aplication(argv, res, count);
	// 	i++;
	// }
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
