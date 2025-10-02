# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 12:47:57 by unovo-ru          #+#    #+#              #
#    Updated: 2025/10/02 18:51:38 by unovo-ru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable name
NAME		= fractol

# Compiler and flags
CC			= cc
CFLAGS		= -Wextra -Wall -Werror -Wunreachable-code -Ofast
RM			= rm -rf

# MLX42 configuration
LIBMLX		= ./MLX42
MLX42_BUILD	= $(LIBMLX)/build
MLX42_LIB	= $(MLX42_BUILD)/libmlx42.a
MLX42_INC	= -I$(LIBMLX)/include

# Libraries and includes
HEADERS		= -I./includes $(MLX42_INC)
LIBS		= $(MLX42_LIB) -ldl -lglfw -pthread -lm

# Source files (add your source files here)
SRCS		= $(shell find ./src -name "*.c" 2>/dev/null || echo "src/main.c")
OBJS		= ${SRCS:.c=.o}

# Colors
CYAN		= \033[96m
RESET		= \033[0m

# Rules
all: libmlx $(NAME)

libmlx:
	@echo "$(CYAN)Building MLX42...$(RESET)"
	@cmake $(LIBMLX) -B $(MLX42_BUILD) && make -C $(MLX42_BUILD) -j4

%.o: %.c
	@echo "$(CYAN)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(NAME): $(OBJS) $(MLX42_LIB)
	@echo "$(CYAN)Creating $(NAME)...$(RESET)"
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(CYAN)$(NAME) created successfully!$(RESET)"

clean:
	@echo "$(CYAN)Cleaning object files...$(RESET)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(CYAN)Cleaning $(NAME)...$(RESET)"
	@$(RM) $(NAME)

mlx_clean:
	@echo "$(CYAN)Cleaning MLX42 build...$(RESET)"
	@$(RM) $(MLX42_BUILD)

re: fclean all

.PHONY: all clean fclean re libmlx mlx_clean