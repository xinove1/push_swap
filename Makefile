NAME= push_swap

LIBFT = ./libft

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRC=push_swap.c stack_utils.c utilities.c parser.c operations.c

BONUS =

BONUS_OBJ = $(BONUS:.c=.o)

OBJ=$(SRC:.c=.o)

$(NAME): $(addprefix src/, $(SRC)) src/push_swap.h
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) -c $(addprefix src/, $(SRC))
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT)/libft.a  -o $(NAME)

all: $(NAME)

bonus: checker.h
	@make -C $(LIBFT)
	$(CC) $(CFLAGS) -c src/$(BONUS)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT)/libft.a  -o $(NAME)

clean:
	@make -C $(LIBFT) clean
	@$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	@make -C $(LIBFT) fclean
	@$(RM) $(NAME) $(BONUS_OBJ)

re: fclean all

.PHONY: clean fclean
