#ifndef ANIMATION_H
# define ANIMATION_H

# include "utils.h"

enum			entity
{
	PLAYER,
	ENEMY,
	EVENT,
	OBJ,
};

typedef struct s_animation
{
	t_list		*frames;
	int			width;
	int			height;
	int			delay;
	int			_tmp_delay;
	int			current_frame_num;
	long int	last_updated;
	long int	frame_count;
	enum entity	entity;
}				t_animation;

void			update_animaiton_anim(void *ptr);

#endif
