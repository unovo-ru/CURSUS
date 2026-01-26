/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:58:51 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/22 20:45:00 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include <stdbool.h>

/* ************************************************************************** */
/*                              DATA STRUCTURES                               */
/* ************************************************************************** */

typedef struct t_node
{
	int				data;			// The integer value stored in the node
	struct t_node	*prev;			// Pointer to the previous node
	struct t_node	*next;			// Pointer to the next node
}			t_node;

/* ************************************************************************** */
/*                                MAIN LOGIC                                  */
/* ************************************************************************** */

/**
 * @brief Entry point of main execution.
 * @param argc Number of arguments.
 * @param argv Argument values.
 * @return 0 on success.
 */
int		main(int argc, char **argv);

/**
 * @brief Entry point of the push_swap algorithm logic.
 * @param str The arguments passed to the program.
 * @return The sorted stack A, or NULL if error.
 */
t_node	*push_swap(char **str);

/**
 * @brief Helper for push_swap initialization.
 * @param str The joined string of arguments.
 * @param arg The original argv array.
 * @return Array of integers parsed from input.
 */
int		*push_swap_extension(char *str, char **arg);

/* ************************************************************************** */
/*                           PARSING & VALIDATION                             */
/* ************************************************************************** */

/**
 * @brief Joins arguments into a single string.
 * @param argv Argument array.
 * @return Joined string.
 */
char	*arg_join(char **argv);

/**
 * @brief Handles null checking for arg_join.
 * @param str String to check.
 */
void	arg_join_extension(char *str);

/**
 * @brief Validates if string contains only numbers and valid signs.
 * @param str String to validate.
 * @return 1 if valid, 0 otherwise.
 */
int		arg_valid(char *str);

/**
 * @brief Checks if number is within integer limits.
 * @param nbr Number to check.
 * @return 1 if within limits, 0 otherwise.
 */
int		is_min_or_max(long int nbr);

/**
 * @brief Converts split strings to integer array.
 * @param new_num_list Array of strings.
 * @param count Number of elements.
 * @return Integer array.
 */
int		*number_array(char **new_num_list, int count);

/**
 * @brief Processes input string into integer array.
 * @param number_list Input string.
 * @return Integer array.
 */
int		*get_imput(char *number_list);

/**
 * @brief Frees string array.
 * @param s Array to free.
 */
void	free_array(char **s);

/**
 * @brief Checks for duplicate numbers.
 * @param numbers Integer array.
 * @param count Size of array.
 * @return 1 if unique, 0 if duplicates found.
 */
int		repeat_number(int *numbers, int count);

/**
 * @brief Prints error message and exits.
 */
void	print_error(void);

/**
 * @brief Checks for empty arguments.
 * @param argv Arguments array.
 * @return 1 if no empty args, 0 otherwise.
 */
int		no_empty_arg(char **argv);

/**
 * @brief Wrapper for input processing (unused in main flow usually).
 * @param str Arguments array.
 * @return Integer array.
 */
int		*final_input(char **str);

/**
 * @brief Counts integers in input string.
 * @param array_ints Input string.
 * @return Count of integers.
 */
int		count_array(char *array_ints);

/* ************************************************************************** */
/*                              NODE OPERATIONS                               */
/* ************************************************************************** */

/**
 * @brief Creates stack from integer array.
 * @param num_array Integer array.
 * @param size Size of array.
 * @return Pointer to head of stack.
 */
t_node	*node_aplication(int *num_array, int size);

/**
 * @brief Creates new node with data.
 * @param data Integer value for node.
 * @return New node pointer.
 */
t_node	*ft_new_node(int data);

/**
 * @brief Adds node to end of valid circular linked list.
 * @param head Pointer to head of list.
 * @param new_node Node to add.
 */
void	ft_node_add_back(t_node **head, t_node *new_node);

/**
 * @brief Gets last node of list.
 * @param lst List head.
 * @return Pointer to last node.
 */
t_node	*ft_last_node(t_node *lst);

/**
 * @brief Adds node to front of list (alternative helper).
 * @param node Head of list.
 * @param new_node Node to add.
 */
void	ft_front_node(t_node **node, t_node *new_node);

/**
 * @brief Frees all nodes in list.
 * @param node Head of list.
 */
void	free_nodes(t_node **node);

/**
 * @brief Gets size of stack.
 * @param stack Stack head.
 * @return Size of stack.
 */
int		stack_size(t_node **stack);

/**
 * @brief Frees stacks and string on error during GNL processing.
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 * @param str String buffer to free.
 */
void	ft_free_stacks(t_node **stack_a, t_node **stack_b, char *str);

/* ************************************************************************** */
/*                                BASIC MOVES                                 */
/* ************************************************************************** */

/**
 * @brief Rotates stack (first becomes last).
 * @param stack Stack to rotate.
 */
void	rotate(t_node **stack);

/**
 * @brief Reverse rotates stack (last becomes first).
 * @param stack Stack to reverse rotate.
 */
void	reverse_rotate(t_node **stack);

/**
 * @brief Swaps first two elements of stack.
 * @param stack Stack to swap.
 */
void	swap(t_node **stack);

/**
 * @brief helper to handle empty stack logic in push.
 * @param stack_source Stack being emptied.
 */
void	empty_dest(t_node **stack_source);

/**
 * @brief Pushes top element from source to dest.
 * @param stack_source Source stack.
 * @param stack_dest Destination stack.
 */
void	push(t_node **stack_source, t_node **stack_dest);

/* ************************************************************************** */
/*                               COSTS & HELPERS                              */
/* ************************************************************************** */

/* Note: These may not be fully utilized in Checker
			bonus but kept for API consistency */

void	do_rr(t_node **stack_a, t_node **stack_b, t_node **cheapest);
void	do_rra(t_node **stack_a, t_node **cheapest);
void	do_ra(t_node **stack_a, t_node **cheapest);
void	do_rrb(t_node **stack_b, t_node **cheapest);
void	do_rb(t_node **stack_b, t_node **cheapest);
void	do_rrr(t_node **stack_a, t_node **stack_b, t_node **cheapest);

/* ************************************************************************** */
/*                                 ACTIONS                                    */
/* ************************************************************************** */

/**
 * @brief Swap A (sa).
 * @param stack_a Stack A.
 */
void	sa(t_node **stack_a);

/**
 * @brief Swap B (sb).
 * @param stack_b Stack B.
 */
void	sb(t_node **stack_b);

/**
 * @brief Swap Both (ss).
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 */
void	ss(t_node **stack_a, t_node **stack_b);

/**
 * @brief Push A (pa).
 * @param stack_a Stack A (dest).
 * @param stack_b Stack B (src).
 */
void	pa(t_node **stack_a, t_node **stack_b);

/**
 * @brief Push B (pb).
 * @param stack_b Stack B (dest).
 * @param stack_a Stack A (src).
 */
void	pb(t_node **stack_b, t_node **stack_a);

/**
 * @brief Rotate A (ra).
 * @param stack_a Stack A.
 */
void	ra(t_node **stack_a);

/**
 * @brief Rotate B (rb).
 * @param stack_b Stack B.
 */
void	rb(t_node **stack_b);

/**
 * @brief Rotate Both (rr).
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 */
void	rr(t_node **stack_a, t_node **stack_b);

/**
 * @brief Reverse Rotate A (rra).
 * @param stack_a Stack A.
 */
void	rra(t_node **stack_a);

/**
 * @brief Reverse Rotate B (rrb).
 * @param stack_b Stack B.
 */
void	rrb(t_node **stack_b);

/**
 * @brief Reverse Rotate Both (rrr).
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 */
void	rrr(t_node **stack_a, t_node **stack_b);

/* ************************************************************************** */
/*                          ALGORITHM & SORTING                               */
/* ************************************************************************** */

/* Note: Most of these are legacy/unused in
			checker bonus but kept for compatibility */

void	index_node(t_node **stack_a, int size);
int		min_aux(int n, t_node *aux, t_node *current);
void	position_node(t_node **stack_a);
int		is_min(t_node **stack_a);
int		is_correct(int *array_ints, int size);
void	select_hc(int size, t_node **stack_a);
void	sort_2(t_node **stack_a);
void	sort_3(t_node **stack_a);
void	sort_stack(t_node **stack_a, t_node **stack_b, int size);
int		cost(t_node **stack, int position);
int		abs_cost(int nbr);
void	cost_both(t_node **stack_a, t_node **stack_b);
void	total_cost(t_node **stack_b);
void	b_target_in_a(t_node **stack_a, t_node **stack_b, t_node *tmp);
t_node	*take_cheapest(t_node **stack);
void	heavy_bucle(t_node **stack_a, t_node **stack_b);
void	this_is_the_way(t_node **stack_a, t_node **stack_b, t_node **cheapest);
void	final_sort(t_node **stack);
int		min_pos_aux(int n, t_node *aux, t_node *current);
int		is_min_pos(t_node **stack_a);

/* ************************************************************************** */
/*                           CHECKER OPERATIONS                               */
/* ************************************************************************** */

/**
 * @brief Checks if stack is sorted.
 * @param stack Stack to check.
 * @return true if sorted, false otherwise.
 */
bool	is_sorted(t_node **stack);

/**
 * @brief Main loop for processing GNL instructions.
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 */
void	gnl_call(t_node **stack_a, t_node **stack_b);

/**
 * @brief Executes instruction from string.
 * @param str Instruction string.
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 */
void	move_if(char *str, t_node **stack_a, t_node **stack_b);

#endif
