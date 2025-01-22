NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lX11 -lXext -lm

SRC = main.c so_long_utils.c physics.c keys_func.c \
	  clean_up.c get_next_line.c render_map.c load_textures.c\
	  read_map.c manage_hooks.c \
	  printf/ft_printf.c printf/ft_putchar.c printf/ft_putnbr_hex_lower.c printf/ft_putnbr_hex_upper.c \
	  printf/ft_putnbr_hex.c printf/ft_putnbr_unsigned.c printf/ft_putnbr.c printf/ft_putstr.c map_valid/bfs.c

OBJ = $(SRC:.c=.o)

LIBFT = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re run