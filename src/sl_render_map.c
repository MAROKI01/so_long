/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 00:39:27 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/21 09:02:38 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_utils.h"

int	create_background(t_data *data)
{
	data->background.ptr = mlx_new_image(data->mlx,
			data->width * data->img_size,
			data->height * data->img_size);
	if (!data->background.ptr)
		return (1);
	data->background.addr = mlx_get_data_addr(data->background.ptr,
			&data->background.bpp,
			&data->background.line_length,
			&data->background.endian);
	return (0);
}

static void	render_walls(t_data *data, int x, int y)
{
	if (y >= 1 && data->grid[y - 1][x] != '1')
		render_tile(data, &data->front_wall, x, y);
	else
		render_tile(data, &data->middle_wall, x, y);
}

static void	render_game_object(t_data *data, int x, int y)
{
	if (data->grid[y][x] == '1')
	{
		render_walls(data, x, y);
	}
	render_player(data, &data->shadow, data->player.p_x + 5,
		data->player.p_y);
	if (data->grid[y][x] == 'E')
	{
		if (data->is_exit_open == 0)
			render_tile(data, &data->exit, x, y);
		else
			render_tile(data, &data->exit_open, x, y);
	}
}

static int	render_grid(t_data *data)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width && data->grid[y][x] != '\n')
		{
			if (data->grid[y][x] != '1')
				render_tile(data, &data->floor, x, y);
			render_game_object(data, x, y);
			x++;
		}
		y++;
	}
	i = 0;
	while (i < data->enemy_count)
	{
		render_tile(data, &data->enemy, data->enemies[i].x, data->enemies[i].y);
		i++;
	}
	return (0);
}

int	render_map(t_data *data)
{
	if (!data)
		return (1);
	if (data->background.ptr)
		mlx_destroy_image(data->mlx, data->background.ptr);
	if (create_background(data))
		return (1);
	if (render_grid(data))
		return (1);
	graphic_counter(data);
	mlx_put_image_to_window(data->mlx, data->win, data->background.ptr, 0, 0);
	return (0);
}
