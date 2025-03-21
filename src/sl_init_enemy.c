/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:14:52 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/21 00:01:22 by ntahadou         ###   ########.fr       */
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
