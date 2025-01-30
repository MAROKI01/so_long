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

//////////////////////////////////////////////////////////////
enum entity {
	PLAYER,
	ENEMY,
	EVENT,
	OBJ,
};
// animation

typedef struct s_list {
    void *content;           // Pointer to the data held by this node
    struct s_list *next;     // Pointer to the next node in the list
} t_list;

typedef struct s_animation {
	t_list *	frames;
	int		width;
	int		height;
	int		delay;			// How many fps it takes to change animation
	int		_tmp_delay;		// Delay Iterator
	int		current_frame_num;	// Which frame is selected
	long int	last_updated;		// When was the last update
	long int	frame_count;		// The frame count
	enum entity	entity;
}		t_animation;

// sprite

typedef struct s_sprite {
	t_list	* animations;
	char	* name;
	char	* file_path;
	t_img	sprite_img;
	int	width;
	int	height;
	int	z_index;
}		t_sprite;

typedef	struct sprite_slice {
	int x;
	int y;
	int width;
	int height;
}	sprite_slice;

/* Sprite */
t_sprite	new_sprite(char * name, char * file_path, t_data *data);
t_animation *	slice_sprite(t_sprite s, sprite_slice slice, int frames, int delay, enum entity e);
void	destroy_sprite(t_sprite s);
#endif