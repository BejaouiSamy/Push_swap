NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
RM = rm -f

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
INC = -I ./includes -I $(LIBFT_PATH)

SRC_PATH = ./src 
SRC = merge_sort.c \
	push_sort.c \
	rotate_sort.c \
	init_stack.c \
	error_checking.c \
	swap_sort.c \
	reverse_rotate.c

OBJ_PATH = ./obj
OBJ = $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) -r $(OBJ_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	$(RM) $(NAME) 
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re