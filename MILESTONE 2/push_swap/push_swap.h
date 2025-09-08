/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:01:55 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/06 16:59:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "./libft/libft.h"

typedef struct t_node
{
	int				index;
	int				data;
	int				cost;
	struct t_node	*prev;
	struct t_node	*next;
}			t_node;

//typedef struct s_list
//{
//	void			*t_node;//t_nbr *
//	struct s_list	*prev;
//	struct s_list	*next;
//}			t_list;


/*!!!!!!! REMEMBER LINK BOTH STRUCTS !!!!!!!!!*/

/*----------------  main  -----------------*/

int		main(int argc, char **argv);

/*-----------  parse arguments  -----------*/
char	*arg_join(char **argv);
int		arg_valid(char *str);
int		is_min_or_max(long int nbr);
int		*number_array(char **new_num_list, int count);
int		*get_imput(char *number_list);
void	free_array(char **s);
int		repeat_number(int *numbers, int count);
//void	print_error(char *array, char **str, int *num, t_node **node);
void	print_error(void);
int		no_empty_arg(char **argv);
int		*final_input(char **str);
int		count_array(char *array_ints);

/*-----------  nodes functions -----------*/

t_node	*node_aplication(int *num_array, int size);
t_node	*ft_new_node(int data);
void	ft_node_add_back(t_node **head, t_node *new_node);
t_node	*ft_last_node(t_node *lst);
void	ft_node_add_back(t_node **node, t_node *new_node);
void	ft_front_node(t_node **node, t_node *new_node);

void	free_nodes(t_node **node);
int		ft_node_size(t_node **stack);

/*------------create the stack b------------*/

t_node	*create_b_stack(void);

/*-----------  print nodes  -----------*/

void	print_node(t_node *node);

/*--------------moves------------------*/
void	rotate(t_node **stack); //CORRECT
void	reverse_rotate(t_node **stack); //CORRECT
void	swap(t_node **stack); //CORRECT


void	push(t_node **stack_source, t_node **stack_dest);


/*-----------------actions---------------*/
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_b, t_node **stack_a);

void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);

void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

/*------------------algorithm------------------*/

void	index_node(t_node *stack_a);
int		is_correct(t_node *stack_a);
// void	select_hc(int size, t_node **stack_a, t_node **stack_b);
void	select_hc(int size, t_node **stack_a);
void	sort_2(t_node **stack_a);
void	sort_3(t_node **stack_a);
void	sort_4(t_node **stack_a, t_node **stack_b);
void	sort_5(t_node **stack_a, t_node **stack_b);
int		is_min(t_node **stack_a);


/*-------------  push swap  --------------*/

t_node	*push_swap(char **str);

/*size_t	ft_let_count(const char *s, char c);
size_t	ft_count_words(const char *s, char c);
char	**free_array(char **s);
char	*ft_substr(char const *s, unsigned int start, size_t len);*/

#endif
