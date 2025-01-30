NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lX11 -lXext -lm

SRC = src/main.c src/animation.c src/image_utils.c src/sprite.c src/window_utils.c src/utils.c

OBJ = $(SRC:.c=.o)

LIBFT = lib/libft.a
MINLIBX = lib/libmlx_Linux.a

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MINLIBX) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: all clean
	@./$(NAME)

.PHONY: all clean fclean re run