NAME=libftprintf.a
AR=ar rcs
CFLAGS=-Wall -Wextra -Werror
RM= rm -f

DIR-LIBRARY = ./libft
LIBFT = $(DIR-LIBRARY)/libft.a

FILES = ft_printf.c \
		ft_var_type.c \
		ft_put_unsig.c \
		ft_hexa.c \
		ft_hexa_max.c \
		ft_hexa_min.c \

OBJ=$(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJ)

$(LIBFT):
	make -C $(DIR-LIBRARY)

%.o: %.c $(LIBFT)
	cc $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C $(DIR-LIBRARY)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(DIR-LIBRARY)

re: fclean all

.PHONY: all clean fclean re