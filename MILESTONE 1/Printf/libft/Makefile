# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 20:42:28 by unovo-ru          #+#    #+#              #
#    Updated: 2025/05/15 21:37:31 by unovo-ru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library file name
NAME = libft.a

# Compiler and compilation flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files and object files
SRC = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \

SRC_BONUS = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

OBJ = $(SRC:%.c=%.o)
OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

INCLUDE = libft.h

# Create library and remove files
AR = ar rcs
RM = rm -f

# Default rule to compile
all: $(NAME)

# Convert .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the library
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# Bonus 
bonus: $(OBJ) $(OBJ_BONUS)
	$(AR) $(NAME) $(OBJ_BONUS)

# Rule to remove the created object files
clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

# Rule to remove the .o and .a files
fclean: clean
	$(RM) $(NAME)

# Recompile everything from scratch
re: fclean all

# Indicates that the following rules are not real files, compiled as commands
.PHONY: all clean fclean re bonus
