/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:12:28 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/21 01:16:40 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_utils.h"
#include "../include/sprite.h"
#include "../include/utils.h"

int	update_animations(void *ptr)
{
	t_data		*data;
	t_list		*animation_node;
	t_animation	*a;

	data = (t_data *)ptr;
	animation_node = data->current_sprite.animations;
	while (animation_node)
	{
		a = (t_animation *)animation_node->content;
		if (a->_tmp_delay++ == a->delay)
			process_player_animation_frame(data, a);
		animation_node = animation_node->next;
	}
	animate_object(data, 'C');
	return (0);
}

t_sprite	init_sprite(t_data *data, char *file_path, int frames,
		t_sprite_slice slice)
{
	t_win			tutorial;
	t_sprite		s1;
	t_sprite_slice	slice1;
	t_sprite_params	params;

	tutorial = data->window;
	s1 = new_sprite_anim("sprite", file_path, &tutorial);
	if (!s1.sprite_img.ptr)
	{
		destroy_sprite_anim(s1);
		destroy_window_anim(tutorial);
		return (s1);
	}
	slice1 = (t_sprite_slice)slice;
	params.data = data;
	params.sprite = s1;
	params.slice = slice1;
	params.frames = frames;
	params.delay = 10000;
	params.entity = PLAYER;
	ft_lstadd_back(&s1.animations, ft_lstnew(slice_sprite_anim(params)));
	ft_printf("Sprite %s [%d %d], loaded %d animations\n", s1.name, s1.width,
		s1.height, ft_lstsize(s1.animations));
	return (s1);
}

int	intialize_animations(t_data *data)
{
	t_sprite_slice	player_slice;
	t_sprite_slice	object_slice;

	player_slice = (t_sprite_slice){0, 0, 109, 109};
	object_slice = (t_sprite_slice){0, 0, 32, 32};
	data->player.direction = LEFT;
	data->sprites.right = init_sprite(data, "textures/sprites/sprite_right.xpm",
			11, player_slice);
	data->sprites.left = init_sprite(data, "textures/sprites/sprite_left.xpm",
			11, player_slice);
	data->sprites.up = init_sprite(data, "textures/sprites/sprite_up.xpm", 11,
			player_slice);
	data->sprites.down = init_sprite(data, "textures/sprites/sprite_down.xpm",
			11, player_slice);
	data->sprites.idle = init_sprite(data, "textures/sprites/sprite_idle.xpm",
			25, player_slice);
	data->sprites.coin = init_sprite(data, "textures/sprites/coin.xpm", 9,
			object_slice);
	return (0);
}

int	animate(t_data *data)
{
	if (!data->window.win_ptr)
		return (2);
	move_enemies(data);
	keys_function(data);
	update_animations(data);
	return (0);
}
