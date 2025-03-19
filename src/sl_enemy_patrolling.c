/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy_patrolling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:00:00 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/19 14:08:34 by ntahadou         ###   ########.fr       */
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

    srand(time(NULL));
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
    do {
        new_direction = rand() % 4;
    } while (new_direction == old_direction);
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

void	move_enemies(t_data *data)
{
    int			i;
    int			new_x;
    int			new_y;
    static int	frame_counter = 0;

    frame_counter++;
    if (frame_counter < 10000)
        return ;
    frame_counter = 0;
    i = 0;
    while (i < data->enemy_count)
    {
        if (rand() % 20 == 0)
            data->enemies[i].direction = rand() % 4;
        calculate_new_position(data, i, &new_x, &new_y);
        if (is_valid_move(data, new_x, new_y))
            process_enemy_move(data, i, new_x, new_y);
        else
            change_enemy_direction(data, i);
        i++;
    }
}