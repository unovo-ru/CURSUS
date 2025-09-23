# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 18:08:01 by unovo-ru          #+#    #+#              #
#    Updated: 2025/09/23 12:17:58 by unovo-ru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable name
NAME = push_swap

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)

# Source and object files
SRC = push_swap.c \
		movements.c \
		arguments_1.c \
		arguments_2.c \
		arguments_3.c \
		node_functions.c \
		fit_num_in_nodes.c \
		algorithm_1.c \
		algorithm_2.c \
		algorithm_3.c \
		target_1.c \
		cost_1.c \
		cost_2.c \
		cost_3.c \
		actions_a.c \
		actions_b.c \
		actions_both.c \
		main.c \
		print_node.c

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# Commands
RM = rm -f


# Colors and symbols
GREEN = \033[1;32m
RED = \033[1;31m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m
CHECK = ✅
CROSS = ❌

# Default rule
all: $(LIBFT) $(NAME)
	@echo "$(GREEN)$(CHECK) Compilation successful!$(RESET)"

# Build executable
$(NAME): $(OBJ)
	@echo "$(YELLOW)Linking objects...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $@

# Compile .c -> .o in obj/
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@echo "$(YELLOW)Linking objects...$(RESET)"
	@$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@

# Create obj/ directory if needed
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Build libft
$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

# Clean object files
clean:
	@$(RM) $(OBJ)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@$(RM) -r $(OBJ_DIR)
	@echo "$(YELLOW)Cleaned object files.$(RESET)"

# Full clean
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@echo "$(BLUE)$(CROSS) Fully cleaned.$(RESET)"

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
