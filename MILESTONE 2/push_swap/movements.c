/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:22:27 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/12 17:55:50 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*

funciones que tendre que hacer para cada uno de los movimientos

	s (swap --> se lo puedo pasar a ambos STACKS A y B)
	ss (doble swap --> se le pasa a ambos al mismo tiempo)
	pa (push --> pasar de B a A)
	pb (push --> pasar de A a B)
	r (rotate --> se puede pasar a ambos nodos rotar todos
			los nodos 1 posicion a la derecha PRIMERO acaba ULTIMO)
	rr (doble rotate --> rota ambos nodos al mismo tiempo)
	rrr (reverse rotate --> se le puede pasar a ambos por separados
			(rra y rrb) y ambos al mismo tiempo (rrr))

*/

void	swap(t_node **stack)
{
	t_node	**h;

	h = stack;
	(*h)->prev->next = (*h)->next;
	(*h)->next->prev = (*h)->prev;
	(*h)->prev = (*h)->next;
	(*h)->next = (*h)->next->next;
	(*h)->prev->next = (*h);
	(*h)->next->prev = (*h);
	(*h) = (*h)->prev;

	/*
	sa
	sb
	ss
	*/
}


/*COMPARAR CON EL DE ABAJO*/

void	push(t_node **stack_source, t_node **stack_dest)
{
	t_node	*a;

	if (!*stack_source)
		return ;
	a = *stack_source;
	empty_dest(stack_source);
	if (!*stack_dest)
	{
		a->next = a;
		a->prev = a;
		*stack_dest = a;
	}
	else
	{
		a->next = *stack_dest;
		a->prev = (*stack_dest)->prev;
		(*stack_dest)->prev->next = a;
		(*stack_dest)->prev = a;
		*stack_dest = a;
	}
}


void	empty_dest(t_node **stack_source)
{
	t_node	*a;

	a = *stack_source;
	if (a->next == a)
		*stack_source = NULL;
	else
	{
		a->prev->next = a->next;
		a->next->prev = a->prev;
		*stack_source = a->next;
	}
}



/*!!!!!!!!!!!!CORRECT!!!!!!!!!!!*/

void	rotate(t_node **stack)
{
	t_node	**h;

	h = stack;
	(*h) = (*h)->next;
}

void	reverse_rotate(t_node **stack)
{
	t_node	**h;

	h = stack;
	(*h) = (*h)->prev;
}
