/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:29:06 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/21 01:30:43 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_utils.h"
#include "../include/sprite.h"
#include "../include/utils.h"

t_sprite	new_sprite_anim(char *name, char *file_path, t_win *win)
{
	t_img	img;

	img = new_file_img_anim(file_path, *win);
	return ((t_sprite){NULL, ft_strdup(name), ft_strdup(file_path), img, img.w,
		img.h, 0});
}

void	add_frame_anim(t_data *data, t_animation *a, t_sprite s,
		t_sprite_slice slice)
{
	t_img	*frame;
	int		i;
	int		j;

	(void)data;
	frame = (t_img *)ft_calloc(sizeof(t_img), 1);
	if (!frame)
		return ;
	*frame = new_img_anim(slice.width, slice.height, s.sprite_img.win);
	i = 0;
	while (i < slice.width)
	{
		j = 0;
		while (j < slice.height)
		{
			put_pixel_img_anim(frame, j, i, get_pixel_img_anim(s.sprite_img,
					slice.x + j, slice.y + i));
			j++;
		}
		i++;
	}
	ft_lstadd_back(&a->frames, ft_lstnew(frame));
}

t_animation	*slice_sprite_anim(t_sprite_params params)
{
	int			i;
	t_animation	*a;

	a = (t_animation *)ft_calloc(sizeof(t_animation), 1);
	if (!a)
		return (NULL);
	*a = (t_animation){NULL, params.slice.width, params.slice.height,
		params.delay, 0, 0, 0, 0, params.entity};
	i = 0;
	while (i < params.frames)
	{
		add_frame_anim(params.data, a, params.sprite, params.slice);
		params.slice.x += params.slice.width;
		if (params.slice.x >= params.sprite.width)
		{
			params.slice.x = 0;
			params.slice.y += params.slice.height;
		}
		i++;
	}
	return (a);
}

void	destroy_sprite_anim(t_sprite s)
{
	free(s.name);
	free(s.file_path);
	destroy_image_anim(s.sprite_img);
}
