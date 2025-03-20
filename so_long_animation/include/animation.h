/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:53:46 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/20 18:02:48 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# include "utils.h"

enum				e_entity
{
	PLAYER,
	ENEMY,
	EVENT,
	OBJ,
};

typedef struct s_sprite_params
{
	t_data			*data;
	t_sprite		sprite;
	t_sprite_slice	slice;
	int				frames;
	int				delay;
	enum e_entity	entity;
}	t_sprite_params;

typedef struct s_animation
{
	t_list			*frames;
	int				width;
	int				height;
	int				delay;
	int				_tmp_delay;
	int				current_frame_num;
	long int		last_updated;
	long int		frame_count;
	enum e_entity	entity;
}					t_animation;

void				update_animaiton_anim(void *ptr);

#endif
