NAME := push_swap

LIBFT := ./libft_ultra/libft.a

CFLAGS := -Wall -Werror -Wextra -g

SRC := main.c\
		preparation.c\
		push_swap.c\
		rules.c\
		functions1.c\
		functions2.c

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) all -C ./libft_ultra
	cc -o $(NAME) $(OBJ) $(LIBFT)

clean:
	$(MAKE) clean -C ./libft_ultra
	rm -f $(OBJ)

fclean:	clean
	$(MAKE) fclean -C./libft_ultra
	rm -f $(NAME)

re:		fclean all
