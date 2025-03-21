/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_clean_up_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:07:46 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/20 18:12:29 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_utils.h"
#include "../so_long_animation/include/animation.h"

static void	free_sprite_names_and_paths(t_sprite *sprite)
{
	if (sprite->name)
	{
		free(sprite->name);
		sprite->name = NULL;
	}
	if (sprite->file_path)
	{
		free(sprite->file_path);
		sprite->file_path = NULL;
	}
}

void	free_sprites(t_data *data)
{
	if (data->sprites.up.sprite_img.ptr)
		mlx_destroy_image(data->mlx, data->sprites.up.sprite_img.ptr);
	free_sprite_names_and_paths(&data->sprites.up);
	if (data->sprites.down.sprite_img.ptr)
		mlx_destroy_image(data->mlx, data->sprites.down.sprite_img.ptr);
	free_sprite_names_and_paths(&data->sprites.down);
	if (data->sprites.left.sprite_img.ptr)
		mlx_destroy_image(data->mlx, data->sprites.left.sprite_img.ptr);
	free_sprite_names_and_paths(&data->sprites.left);
	if (data->sprites.right.sprite_img.ptr)
		mlx_destroy_image(data->mlx, data->sprites.right.sprite_img.ptr);
	free_sprite_names_and_paths(&data->sprites.right);
	if (data->sprites.idle.sprite_img.ptr)
		mlx_destroy_image(data->mlx, data->sprites.idle.sprite_img.ptr);
	free_sprite_names_and_paths(&data->sprites.idle);
	if (data->sprites.coin.sprite_img.ptr)
		mlx_destroy_image(data->mlx, data->sprites.coin.sprite_img.ptr);
	free_sprite_names_and_paths(&data->sprites.coin);
	if (data->sprites.enemy.sprite_img.ptr)
		mlx_destroy_image(data->mlx, data->sprites.enemy.sprite_img.ptr);
	free_sprite_names_and_paths(&data->sprites.enemy);
}

static void	free_frames(t_list *frames)
{
	t_list	*tmp;

	while (frames)
	{
		tmp = frames->next;
		if (((t_img *)frames->content)->ptr)
			mlx_destroy_image(((t_img *)frames->content)->win.mlx_ptr,
				((t_img *)frames->content)->ptr);
		free(frames->content);
		free(frames);
		frames = tmp;
	}
}

static void	free_animations(t_list *animations)
{
	t_list	*tmp;

	while (animations)
	{
		tmp = animations->next;
		free_frames(((t_animation *)animations->content)->frames);
		free(animations->content);
		free(animations);
		animations = tmp;
	}
}

void	free_animation(t_data *data)
{
	free_animations(data->sprites.up.animations);
	free_animations(data->sprites.down.animations);
	free_animations(data->sprites.left.animations);
	free_animations(data->sprites.right.animations);
	free_animations(data->sprites.idle.animations);
	free_animations(data->sprites.coin.animations);
	free_animations(data->sprites.enemy.animations);
}
