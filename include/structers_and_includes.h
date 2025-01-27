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

typedef struct s_data {
    void    *mlx;
    void    *win;
	char    **grid;     
    int     width;      
    int     height;
	t_img   background;
	// for the wall  
    t_img    front_wall;
    t_img    middle_wall;

    t_img    floor;     
    t_img    collect;   
    t_img    exit;    
    t_img    exit_open;
    t_img    player; 

    int     img_size;
	int 	moves_counter;
	int		is_exit_open;
	int		total_coins;

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
} t_data;
#endif