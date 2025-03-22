/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy_patrolling_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:17:07 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/22 17:52:21 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_utils.h"
#include <stdlib.h>
#include <time.h>

int	is_valid_move(t_data *data, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= data->width)
		return (0);
	if (new_y < 0 || new_y >= data->height)
		return (0);
	if (data->grid[new_y][new_x] == '0'
		|| data->grid[new_y][new_x] == 'C')
		return (1);
	return (0);
}

void	process_enemy_move(t_data *data, int i, int new_x, int new_y)
{
	if (data->grid[data->enemies[i].y][data->enemies[i].x] != 'C')
		data->grid[data->enemies[i].y][data->enemies[i].x] = '0';
	data->enemies[i].x = new_x;
	data->enemies[i].y = new_y;
	if (data->grid[new_y][new_x] != 'C')
		data->grid[new_y][new_x] = 'A';
}

void	change_enemy_direction(t_data *data, int i)
{
	int	old_direction;
	int	new_direction;

	old_direction = data->enemies[i].direction;
	new_direction = rand() % 4;
	while (new_direction == old_direction)
	{
		new_direction = rand() % 4;
	}
	data->enemies[i].direction = new_direction;
}

void	calculate_new_position(t_data *data, int i, int *new_x, int *new_y)
{
	*new_x = data->enemies[i].x;
	*new_y = data->enemies[i].y;
	if (data->enemies[i].direction == 0)
		(*new_x)++;
	else if (data->enemies[i].direction == 1)
		(*new_y)++;
	else if (data->enemies[i].direction == 2)
		(*new_x)--;
	else if (data->enemies[i].direction == 3)
		(*new_y)--;
}

int	is_player_nearby(t_data *data, int enemy_x, int enemy_y)
{
	int	player_grid_x;
	int	player_grid_y;
	int	distance;

	player_grid_x = data->player.p_x / IMG_SIZE;
	player_grid_y = data->player.p_y / IMG_SIZE;
	distance = abs(player_grid_x - enemy_x) + abs(player_grid_y - enemy_y);
	return (distance <= 5);
}
