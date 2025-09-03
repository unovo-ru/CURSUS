/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:22:27 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/03 20:56:30 by marvin           ###   ########.fr       */
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
	t_node *a;

	if (!*stack_source)
		return;
	a = *stack_source;
	// Si solo hay un nodo en stack_source
	a->prev->next = a->next;
	a->next->prev = a->prev;
	*stack_source = a->next;
	if (!*stack_dest)
	{
	// Stack destino vacío: el nodo apunta a sí mismo
		a->next = a;
		a->prev = a;
		*stack_dest = a;
	}
	else
	{
	// Insertar al inicio del stack_dest
		a->next = *stack_dest;
		a->prev = (*stack_dest)->prev;
		(*stack_dest)->prev->next = a;
		(*stack_dest)->prev = a;
		*stack_dest = a;
	}
}

/*void	push(t_node **stack_source, t_node **stack_dest)
{
	t_node	**a;
	t_node	**b;

	a = stack_source;
	b = stack_dest;
	if (!*stack_source)
		return;
	if (ft_node_size(b) == 0)
		{
			(*a)->prev->next = (*a)->next;
			(*a)->next->prev = (*a)->prev;
			(*b) = (*a);
			(*b)->prev = (*b);
			(*b)->next = (*b);
		}
	else if (ft_node_size(b) > 0)
		{
			(*a)->prev->next = (*a)->next;
			(*a)->next->prev = (*a)->prev;
			(*a)->prev = (*b)->prev;
			(*b)->prev = (*a);
			(*b)->prev->prev->next = (*a);
			(*a) = (*a)->next;
			(*b)->prev->next = (*b);
			(*b) = (*b)->prev;
		}
}*/

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
