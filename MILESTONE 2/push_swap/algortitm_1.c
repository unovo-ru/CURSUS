/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algortitm_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:54:13 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/05 16:40:26 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_correct(t_node *stack_a)
{
	t_node	*aux;

	aux = stack_a;
	while (1)
	{
		if (stack_a == aux) /*estan ordenados salgo al volver al inicio*/
			return (0);
		if (stack_a->data < stack_a->next->data) /*mientras esten ordenados
													itero para encontrar donde no
													lo estan*/
			continue ;
		if (stack_a->data > stack_a->next->data) /*rompemos en el momento que 
															deje
														de estar ordenado*/
			return (1);
	}
	return (0);
}


/*void	sort_2(t_node stack_a)
{
	
}

void	sort_3(t_node stack_a)
{
	
}*/
