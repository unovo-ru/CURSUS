/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:59:20 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/08/28 13:41:24 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
	(void)argc;
	int i = 0;
	char *join_arguments = NULL;
	/*if (no_empty_arg(argv))
		join_arguments = arg_join(argv);
	else
		print_error();*/
	printf("esto son mis args unidos --> %s\n\n", join_arguments);
	int *array = get_imput(join_arguments);
	while (i < 4)
	{
		printf("esto es mi imput = %d\n", array[i]);
		i++;
	}
	return (0);
}
