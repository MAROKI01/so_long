NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lX11 -lXext -lm

SRC = src/main.c src/get_next_line.c src/sl_clean_up.c src/sl_img_utils.c src/sl_keys_func.c src/sl_load_textures.c \
		src/sl_graphic_counter.c \
		src/sl_manage_hooks.c src/sl_read_map.c src/sl_read_map_utils.c src/sl_render_map.c src/sl_render_map_utils.c src/sl_utils.c \
	  printf/ft_printf.c printf/ft_putchar.c printf/ft_putnbr_hex_lower.c printf/ft_putnbr_hex_upper.c \
	  printf/ft_putnbr_hex.c printf/ft_putnbr_unsigned.c printf/ft_putnbr.c printf/ft_putstr.c \
	  map_valid/bfs.c map_valid/map_checker.c 

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