/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:12:55 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/21 01:26:59 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_utils.h"
#include "../include/sprite.h"
#include "../include/utils.h"

t_list	*get_animation_list(t_data *data, int object)
{
	if (object == 'C')
		return (data->sprites.coin.animations);
	else if (object == 'A')
		return (data->sprites.enemy.animations);
	return (NULL);
}

void	render_object_frame(t_data *data, t_img *img, int object)
{
	int	row;
	int	col;

	row = 0;
	while (row < data->height)
	{
		col = 0;
		while (col < data->width)
		{
			if (data->grid[row][col] == object)
				render_player(data, img, col * IMG_SIZE, row * IMG_SIZE);
			col++;
		}
		row++;
	}
}

void	process_animation_frame(t_data *data, t_animation *a, int object)
{
	t_img	*img;

	a->_tmp_delay = 0;
	a->current_frame_num++;
	a->current_frame_num %= ft_lstsize(a->frames);
	img = (t_img *)ft_lstget_anim(a->frames, a->current_frame_num)->content;
	render_object_frame(data, img, object);
	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr,
		data->background.ptr, 0, 0);
}

int	animate_object(void *ptr, int object)
{
	t_data		*data;
	t_list		*animation_node;
	t_animation	*a;

	data = (t_data *)ptr;
	animation_node = get_animation_list(data, object);
	while (animation_node)
	{
		a = (t_animation *)animation_node->content;
		if (a->_tmp_delay++ == a->delay)
			process_animation_frame(data, a, object);
		animation_node = animation_node->next;
	}
	return (0);
}

void	process_player_animation_frame(t_data *data, t_animation *a)
{
	t_img	*img;

	a->_tmp_delay = 0;
	a->current_frame_num++;
	a->current_frame_num %= ft_lstsize(a->frames);
	img = (t_img *)ft_lstget_anim(a->frames, a->current_frame_num)->content;
	render_map(data);
	render_player(data, img, data->player.p_x, data->player.p_y);
	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr,
		data->background.ptr, 0, 0);
}
