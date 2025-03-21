/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:09:32 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/21 01:10:15 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_utils.h"

void	init_player_pos(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->grid[y][x] == 'P')
			{
				data->player.p_x = x * IMG_SIZE;
				data->player.p_y = y * IMG_SIZE;
				return ;
			}
			x++;
		}
		y++;
	}
	data->total_coins_number = object_counter(data, 'C');
}

int	object_counter(t_data *data, char object)
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
			if (data->grid[y][x] == object)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
