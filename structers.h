#ifndef STRUCTERS_H
#define STRUCTERS_H

#define MAX_KEYS 256
#define BUFFER_SIZE 10
#define IMG_SIZE 32
#define PLAYER_H 32
#define PLAYER_W 16 
#define PLAYER_SPEED 10

#include <X11/X.h>
#include <X11/keysym.h>
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>

#include "libft.h"
#include "printf/ft_printf.h"

enum objects {
	wall,
	exit_g,
	collectible,
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
		float 	p_x;
		float	p_y;
		
} t_img;

typedef struct s_data {
    void    *mlx;
    void    *win;
	int		keys[256];
	char    **grid;     
    int     width;      
    int     height;
	t_img   background;
	// for the wall  
    t_img    front_wall;
    t_img    back_wall;      
    t_img    left_wall;      
    t_img    right_wall;      
    t_img    corner_wall;
    t_img    middle_wall;

	int		move_right;
	int		move_left;
	int		move_up;
	int		move_down;

    t_img    floor;     
    t_img    collect;   
    t_img    exit;      
    t_img    player;   
    int     img_size;
	int		coins_count;
	int 	moves_counter;
} t_data;

#endif