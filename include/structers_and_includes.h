#ifndef STRUCTERS_H
#define STRUCTERS_H

#define MAX_KEYS 256
#define BUFFER_SIZE 10
#define IMG_SIZE 32
#define PLAYER_H 109
#define PLAYER_W 109 
#define PLAYER_STEP 8

#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>

#include "mlx.h"
#include "libft.h"
#include "ft_printf.h"

typedef	struct sprite_slice {
	int x;
	int y;
	int width;
	int height;
}	sprite_slice;

typedef enum e_direction {
    IDLE,
    UP,
    DOWN,
    LEFT,
    RIGHT
} t_direction;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;	
	int		height;	
}		t_win;

typedef struct s_img
{
	t_win	win;
	void	*ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_length;
	int 	p_x;
	int		p_y;
	int		direction;
}		t_img;

typedef struct s_digits
{
	t_img	zero;
	t_img	one;
	t_img	two;
	t_img	three;
	t_img	four;
	t_img	five;
	t_img	six;
	t_img	seven;
	t_img	eight;
	t_img	nine;
	t_img	move_n;
}t_digits;

typedef struct s_sprite {
	t_list	* animations;
	char	* name;
	char	* file_path;
	t_img	sprite_img;
	int	width;
	int	height;
	int	z_index;
}		t_sprite;

typedef struct s_game_sprites {
    t_sprite up;
    t_sprite down;
    t_sprite left;
    t_sprite right;
	t_sprite idle;
	t_sprite coin;
	t_sprite enemy;
} t_game_sprites;

typedef struct s_data {
	t_win	window;
    void    *mlx;
    void    *win;
	char    **grid;  
	int		keys[256];   
    int     width;      
    int     height;
	t_img   background;
    t_img    front_wall;
    t_img    middle_wall;
    t_img    floor;     
    t_img    collect;   
    t_img    exit;    
    t_img    exit_open;
    t_img    player;
	t_img	 enemy;
    int     img_size;
	int 	moves_counter;
	int		is_exit_open;
	int		total_coins;
	struct s_digits digits;
	t_sprite current_sprite;
	t_game_sprites sprites;
	int total_coins_number;
	int coin_counter;
} t_data;

typedef struct s_collision_box
{
    int	offset_left;
    int	offset_right;
    int	offset_top;
    int	offset_bottom;
    int	col_x;
    int	col_y;
    int	col_w;
    int	col_h;
    int center_y;
    int center_x;
    int	sample_step;
}				t_collision_box;

#endif