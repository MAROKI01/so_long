#ifndef STRUCTERS_H
#define STRUCTERS_H

#define MAX_KEYS 256
#define BUFFER_SIZE 10
#define IMG_SIZE 32
#define PLAYER_H 20
#define PLAYER_W 20 
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

enum state {
	idle,
	right,
	up
};

typedef struct s_img
{
		void	*addr;
		void	*ptr;
		int		line_length;
		int		bpp;
		int		endian;
		int		w;
		int		h;
		int 	p_x;
		int		p_y;
} t_img;

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

typedef struct s_dirc
{
	int left;
	int right;
	int up;
	int down;
}t_dirc;


typedef struct s_sprite
{
	t_img *frames;
	int frame_count;
    int current_frame; 
	int total_frames;
} t_sprite;

typedef struct s_object_sprites
{
	t_sprite player_idle;
	t_sprite player_up;
	t_sprite player_right;

} t_object_sprites;

typedef struct s_data {
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
	t_dirc direction;
	t_object_sprites objects;
} t_data;

#endif