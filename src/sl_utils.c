/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:09:32 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/21 10:03:44 by ntahadou         ###   ########.fr       */
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

int	limit_window_size(t_data *data)
{
	int	max_width;
	int	max_height;

	max_width = 1920;
	max_height = 1080;
	if (data->width * IMG_SIZE > max_width
		|| data->height * IMG_SIZE > max_height)
	{
		ft_printf("Error: Map size exceeds maximum window dimensions.");
		clean_up(data);
		exit(1);
	}
	return (1);
}
