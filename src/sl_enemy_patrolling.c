/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy_patrolling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:11:59 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/19 17:14:39 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_utils.h"
#include <stdlib.h>
#include <time.h>

static int	count_enemies(t_data *data)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->grid[y][x] == 'A')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static void	init_single_enemy(t_data *data, int *count, int x, int y)
{
	data->enemies[*count].x = x;
	data->enemies[*count].y = y;
	data->enemies[*count].direction = rand() % 4;
	data->enemies[*count].move_counter = 0;
	(*count)++;
}

void	initialize_enemies(t_data *data)
{
	int	x;
	int	y;
	int	count;
	int	enemy_count;

	enemy_count = count_enemies(data);
	data->enemy_count = enemy_count;
	if (enemy_count == 0)
		return ;
	data->enemies = malloc(sizeof(t_enemy) * enemy_count);
	if (!data->enemies)
		return ;
	count = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->grid[y][x] == 'A')
				init_single_enemy(data, &count, x, y);
			x++;
		}
		y++;
	}
}

static int	is_valid_move(t_data *data, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= data->width)
		return (0);
	if (new_y < 0 || new_y >= data->height)
		return (0);
	if (data->grid[new_y][new_x] != '0')
		return (0);
	return (1);
}

static void	process_enemy_move(t_data *data, int i, int new_x, int new_y)
{
	data->grid[data->enemies[i].y][data->enemies[i].x] = '0';
	data->enemies[i].x = new_x;
	data->enemies[i].y = new_y;
	data->grid[new_y][new_x] = 'A';
}

static void	change_enemy_direction(t_data *data, int i)
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

static void	calculate_new_position(t_data *data, int i, int *new_x, int *new_y)
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
static int	is_player_nearby(t_data *data, int enemy_x, int enemy_y)
{
	int	player_grid_x;
	int	player_grid_y;
	int	distance;

	player_grid_x = data->player.p_x / IMG_SIZE;
	player_grid_y = data->player.p_y / IMG_SIZE;
	distance = abs(player_grid_x - enemy_x) + abs(player_grid_y - enemy_y);
	return (distance <= 5);
}

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
			data->enemies[i].direction = 1; // Down
		else
			data->enemies[i].direction = 3; // Up
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
	return (player_x < enemy_pixel_x + IMG_SIZE &&
			player_x + IMG_SIZE > enemy_pixel_x &&
			player_y < enemy_pixel_y + IMG_SIZE &&
			player_y + IMG_SIZE > enemy_pixel_y);
}

void	check_enemy_collisions(t_data *data)
{
	int	i;

	for (i = 0; i < data->enemy_count; i++)
	{
		if (is_player_colliding_with_enemy(data,
											data->enemies[i].x,
											data->enemies[i].y))
		{
			ft_printf("Game over! You were caught by an enemy!\n");
			clean_up(data);
			exit(0);
		}
	}
}

void	move_enemies(t_data *data)
{
	int i;
	int new_x;
	int new_y;
	static int frame_counter = 0;

	frame_counter++;
	if (frame_counter < 20000)
		return ;
	frame_counter = 0;
	check_enemy_collisions(data);
	i = 0;
	while (i < data->enemy_count)
	{
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
		i++;
	}
	check_enemy_collisions(data);
}