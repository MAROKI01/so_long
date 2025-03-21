/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy_patrolling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:11:59 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/20 18:24:07 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_utils.h"
#include <stdlib.h>
#include <time.h>

static void	set_direction_towards_player(t_data *data, int i)
{
	int	player_grid_x;
	int	player_grid_y;
	int	dx;
	int	dy;

	player_grid_x = data->player.p_x / IMG_SIZE;
	player_grid_y = data->player.p_y / IMG_SIZE;
	dx = player_grid_x - data->enemies[i].x;
	dy = player_grid_y - data->enemies[i].y;
	if (abs(dx) > abs(dy))
	{
		if (dx > 0)
			data->enemies[i].direction = 0;
		else
			data->enemies[i].direction = 2;
	}
	else
	{
		if (dy > 0)
			data->enemies[i].direction = 1;
		else
			data->enemies[i].direction = 3;
	}
}

static int	is_player_colliding_with_enemy(t_data *data, int enemy_x,
		int enemy_y)
{
	int	player_x;
	int	player_y;
	int	enemy_pixel_x;
	int	enemy_pixel_y;

	player_x = data->player.p_x;
	player_y = data->player.p_y;
	enemy_pixel_x = enemy_x * IMG_SIZE;
	enemy_pixel_y = enemy_y * IMG_SIZE;
	return (player_x < enemy_pixel_x + IMG_SIZE
		&& player_x + IMG_SIZE > enemy_pixel_x
		&& player_y < enemy_pixel_y + IMG_SIZE
		&& player_y + IMG_SIZE > enemy_pixel_y);
}

static void	check_enemy_collisions(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->enemy_count)
	{
		if (is_player_colliding_with_enemy(data,
				data->enemies[i].x,
				data->enemies[i].y))
		{
			ft_printf("Game over! You were caught by an enemy!\n");
			clean_up(data);
			exit(0);
		}
		i++;
	}
}

static void	update_enemy_position(t_data *data, int i)
{
	int	new_x;
	int	new_y;

	if (is_player_nearby(data, data->enemies[i].x, data->enemies[i].y))
	{
		set_direction_towards_player(data, i);
	}
	else if (rand() % 20 == 0)
	{
		data->enemies[i].direction = rand() % 4;
	}
	calculate_new_position(data, i, &new_x, &new_y);
	if (is_valid_move(data, new_x, new_y))
		process_enemy_move(data, i, new_x, new_y);
	else
		change_enemy_direction(data, i);
}

void	move_enemies(t_data *data)
{
	int			i;
	static int	frame_counter = 0;

	frame_counter++;
	if (frame_counter < 20000)
		return ;
	frame_counter = 0;
	check_enemy_collisions(data);
	i = 0;
	while (i < data->enemy_count)
	{
		update_enemy_position(data, i);
		i++;
	}
	check_enemy_collisions(data);
}
