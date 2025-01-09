#ifndef STRUCTERS_H
#define STRUCTERS_H

#define MAX_KEYS 256

#include <X11/X.h>
#include <X11/keysym.h>
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#include "libft.h"


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
	t_img 	bg;
    t_img	image;
	int		keys[256];
	char    **grid;     
    int     width;      
    int     height;     
    t_img    *wall;      
    void    *floor;     
    void    *collect;   
    void    *exit;      
    void    *player;   
    int     img_size; 
} t_data;

#endif