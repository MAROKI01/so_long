#ifndef SPRITE_H
# define SPRITE_H

# include "utils.h"



typedef	struct sprite_slice {
	int x;
	int y;
	int width;
	int height;
}	sprite_slice;

/* Sprite */
t_sprite	new_sprite_anim(char * name, char * file_path, t_win * win);
t_animation *	slice_sprite_anim(t_data *data, t_sprite s, sprite_slice slice, int frames, int delay, enum entity e);
void	destroy_sprite_anim(t_sprite s);
#endif
