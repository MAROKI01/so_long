/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_keys_func_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 00:02:37 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/21 09:18:48 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_utils.h"

int	key_press(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == XK_Escape)
	{
		clean_up(data);
		exit(0);
	}
	if (keycode >= 0 && keycode < MAX_KEYS)
	{
		data->keys[keycode] = 1;
	}
	return (0);
}

int	key_release(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode >= 0 && keycode < MAX_KEYS)
	{
		data->keys[keycode] = 0;
	}
	return (0);
}

void	handle_coin_collection(t_data *data, int new_x, int new_y)
{
	t_collision_box	box;
	int				grid_y;
	int				grid_x;

	box.offset_left = 60;
	box.offset_right = 0;
	box.offset_top = 0;
	box.offset_bottom = 10;
	box.center_x = new_x + (box.offset_left + box.offset_right) / 2;
	box.center_y = new_y + (box.offset_top + box.offset_bottom) / 2;
	grid_x = box.center_x / IMG_SIZE;
	grid_y = box.center_y / IMG_SIZE;
	if (data->grid[grid_y][grid_x] == 'C')
	{
		data->coin_counter++;
		data->grid[grid_y][grid_x] = '0';
	}
	if (data->total_coins == data->coin_counter)
		data->is_exit_open = 1;
}

int	check_cell(t_data *data, char object, int x, int y)
{
	int	grid_x;
	int	grid_y;

	grid_x = x / IMG_SIZE;
	grid_y = y / IMG_SIZE;
	if (grid_y < 0 || grid_y >= data->height || grid_x < 0
		|| grid_x >= data->width)
		return (0);
	if (data->grid[grid_y][grid_x] == object)
		return (1);
	return (0);
}

void	update_movement_keys(t_data *data, int check)
{
	if (data->keys[XK_w] && check != 0)
	{
		data->player.p_y -= PLAYER_STEP;
		data->player.direction = UP;
		data->current_sprite = data->sprites.up;
	}
	if (data->keys[XK_s] && check != 0)
	{
		data->player.p_y += PLAYER_STEP;
		data->player.direction = DOWN;
		data->current_sprite = data->sprites.down;
	}
	if (data->keys[XK_d] && check != 0)
	{
		data->player.p_x += PLAYER_STEP;
		data->player.direction = RIGHT;
		data->current_sprite = data->sprites.right;
	}
	if (data->keys[XK_a] && check != 0)
	{
		data->player.p_x -= PLAYER_STEP;
		data->player.direction = LEFT;
		data->current_sprite = data->sprites.left;
	}
}
