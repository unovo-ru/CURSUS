/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:01:55 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/22 20:30:15 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

/* ************************************************************************** */
/*                              DATA Structures                               */
/* ************************************************************************** */

typedef struct t_node
{
	int				index;			// Rank of the number (0 to size-1)
	int				data;			// The actual integer value
	int				cost_a;			// Cost to rotate stack A
	int				cost_b;			// Cost to rotate stack B
	int				total_cost;		// Total combined cost to move node
	int				pos;			// Current position in the stack
	int				target;			// Target position index in the other stack
	struct t_node	*prev;			// Pointer to the previous node
	struct t_node	*next;			// Pointer to the next node
}			t_node;

/* ************************************************************************** */
/*                                MAIN LOGIC                                  */
/* ************************************************************************** */

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
 * @brief Pushes top element from source to dest.
 * @param stack_source Source stack.
 * @param stack_dest Destination stack.
 */
void	push(t_node **stack_source, t_node **stack_dest);

/**
 * @brief helper to handle empty stack logic in push.
 * @param stack_source Stack being emptied.
 */
void	empty_dest(t_node **stack_source);

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

/**
 * @brief Assigns indices to nodes based on value rank.
 * @param stack_a Stack A.
 * @param size Size of stack.
 */
void	index_node(t_node **stack_a, int size);

/**
 * @brief Assigns current position to each node.
 * @param stack_a Stack A.
 */
void	position_node(t_node **stack_a);

/**
 * @brief Checks if array is sorted.
 * @param array_ints Array of integers.
 * @param size Size of array.
 * @return 0 if sorted, 1 otherwise.
 */
int		is_correct(int *array_ints, int size);

/**
 * @brief Selects sorting algorithm based on size.
 * @param size Size of stack.
 * @param stack_a Stack A.
 */
void	select_hc(int size, t_node **stack_a);

/**
 * @brief Hardcoded sort for 2 elements.
 * @param stack_a Stack A.
 */
void	sort_2(t_node **stack_a);

/**
 * @brief Hardcoded sort for 3 elements.
 * @param stack_a Stack A.
 */
void	sort_3(t_node **stack_a);

/**
 * @brief Main sort logic dealing with pushing to B.
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 * @param size Total size.
 */
void	sort_stack(t_node **stack_a, t_node **stack_b, int size);

/**
 * @brief Calculates cost to move element to top.
 * @param stack Stack containing element.
 * @param position Current position.
 * @return Cost value.
 */
int		cost(t_node **stack, int position);

/**
 * @brief Calculates absolute value.
 * @param nbr Number.
 * @return Absolute value.
 */
int		abs_cost(int nbr);

/**
 * @brief Calculates move costs for elements in B to match targets in A.
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 */
void	cost_both(t_node **stack_a, t_node **stack_b);

/**
 * @brief Sums costs to find total move cost.
 * @param stack_b Stack B.
 */
void	total_cost(t_node **stack_b);

/**
 * @brief Finds target position in A for elements in B.
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 * @param tmp Temp variable pointer (unused by caller).
 */
void	b_target_in_a(t_node **stack_a, t_node **stack_b, t_node *tmp);

/**
 * @brief Finds node with cheapest move cost in stack.
 * @param stack Stack to search.
 * @return Pointer to cheapest node.
 */
t_node	*take_cheapest(t_node **stack);

/**
 * @brief Main loop for pushing elements back from B to A.
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 */
void	heavy_bucle(t_node **stack_a, t_node **stack_b);

/**
 * @brief Executes moves for cheapest element.
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 * @param cheapest Pointer to cheapest node.
 */
void	this_is_the_way(t_node **stack_a, t_node **stack_b, t_node **cheapest);

/**
 * @brief Final rotation to put min element at top.
 * @param stack Stack A.
 */
void	final_sort(t_node **stack);

/**
 * @brief Finds minimum value in stack.
 * @param stack_a Stack A.
 * @return Minimum value.
 */
int		is_min(t_node **stack_a);

/**
 * @brief Helper for finding min value logic.
 * @param n Current min.
 * @param aux Start node.
 * @param current Iterator node.
 * @return Min value.
 */
int		min_aux(int n, t_node *aux, t_node *current);

/**
 * @brief Helper for finding position of min value logic.
 * @param n Current min pos.
 * @param aux Start node.
 * @param current Iterator node.
 * @return Min pos value.
 */
int		min_pos_aux(int n, t_node *aux, t_node *current);

/**
 * @brief Finds position of minimum value.
 * @param stack_a Stack A.
 * @return Position index.
 */
int		is_min_pos(t_node **stack_a);

/* ************************************************************************** */
/*                            STRATEGIC MOVES                                 */
/* ************************************************************************** */

/**
 * @brief Executes rr and updates costs.
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 * @param cheapest Cost tracker node.
 */
void	do_rr(t_node **stack_a, t_node **stack_b, t_node **cheapest);

/**
 * @brief Executes rra and updates costs.
 * @param stack_a Stack A.
 * @param cheapest Cost tracker node.
 */
void	do_rra(t_node **stack_a, t_node **cheapest);

/**
 * @brief Executes ra and updates costs.
 * @param stack_a Stack A.
 * @param cheapest Cost tracker node.
 */
void	do_ra(t_node **stack_a, t_node **cheapest);

/**
 * @brief Executes rrb and updates costs.
 * @param stack_b Stack B.
 * @param cheapest Cost tracker node.
 */
void	do_rrb(t_node **stack_b, t_node **cheapest);

/**
 * @brief Executes rb and updates costs.
 * @param stack_b Stack B.
 * @param cheapest Cost tracker node.
 */
void	do_rb(t_node **stack_b, t_node **cheapest);

/**
 * @brief Executes rrr and updates costs.
 * @param stack_a Stack A.
 * @param stack_b Stack B.
 * @param cheapest Cost tracker node.
 */
void	do_rrr(t_node **stack_a, t_node **stack_b, t_node **cheapest);

#endif
