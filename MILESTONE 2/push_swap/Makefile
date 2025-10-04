# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 18:08:01 by unovo-ru          #+#    #+#              #
#    Updated: 2025/10/04 03:03:49 by unovo-ru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable name
NAME = push_swap

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)

# Source and object files
SRCDIR=src

SRC = 	push_swap.c \
		movements.c \
		arguments_1.c \
		arguments_2.c \
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

ALLFILES:=$(addprefix $(SRCDIR)/, $(SRC))

OBJ_DIR = obj
# OBJ = $(ALLFILES:%.c=$(OBJ_DIR)/%.o)
OBJ = $(patsubst $(SRCDIR)/%, $(OBJ_DIR)/%, $(ALLFILES:%.c=%.o))

SRC_BONUS_DIR=src_bonus

SRC_BONUS= push_swap_bonus.c \
		movements_bonus.c \
		arguments_1_bonus.c \
		arguments_2_bonus.c \
		arguments_3_bonus.c \
		node_functions_bonus.c \
		fit_num_in_nodes_bonus.c \
		actions_a_bonus.c \
		actions_b_bonus.c \
		actions_both_bonus.c \
		main_bonus.c \
		stack_size_bonus.c \


ALLFILES_BONUS:=$(addprefix $(SRC_BONUS_DIR)/, $(SRC_BONUS))

OBJ_DIR_BONUS= obj_bonus

# OBJ = $(ALLFILES:%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS = $(patsubst $(SRC_BONUS_DIR)/%, $(OBJ_DIR_BONUS)/%, $(ALLFILES_BONUS:%.c=%.o))


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
$(OBJ_DIR)/%.o: $(SRCDIR)/%.c | $(OBJ_DIR)
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
	@$(RM) $(OBJ) $(OBJ_BONUS)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@$(RM) -r $(OBJ_DIR) $(OBJ_DIR_BONUS)
	@echo "$(YELLOW)Cleaned object files.$(RESET)"

# Full clean
fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@echo "$(BLUE)$(CROSS) Fully cleaned.$(RESET)"

# Rebuild everything
re: fclean all

BONUS_NAME=checker

$(OBJ_DIR_BONUS):
	@mkdir -p $(OBJ_DIR_BONUS)

$(OBJ_DIR_BONUS)/%.o: $(SRC_BONUS_DIR)/%.c | $(OBJ_DIR_BONUS)
	@echo "$(YELLOW)Linking bonus objects...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ_BONUS) $(LIBFT)
	@echo "$(YELLOW)Linking bonus objects...$(RESET)"
	@echo "$(GREEN)$(CHECK) Compilation successful!$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(BONUS_NAME)


.PHONY: all clean fclean re
