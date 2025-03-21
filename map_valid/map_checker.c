/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 03:08:34 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/21 02:03:11 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_utils.h"

static int	map_bound_checker(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->width)
	{
		if (data->grid[0][i] != '1' || data->grid[data->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < data->height)
	{
		if (data->grid[i][0] != '1' || data->grid[i][data->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	count_items(t_data *data)
{
	int	exit;
	int	player;

	data->total_coins = object_counter(data, 'C');
	exit = object_counter(data, 'E');
	player = object_counter(data, 'P');
	if (data->total_coins == 0)
	{
		printf("Error: Too few coins");
		return (0);
	}
	if (exit > 1 || exit == 0)
	{
		printf("Error: Map invalid");
		return (0);
	}
	if (player == 0 || player > 1)
	{
		printf("Error: Required one player");
		return (0);
	}
	return (1);
}

static int	bfs_checker(t_data *data)
{
	int	collectibles;
	int	exit_found;

	bfs((t_bfs_params){data->grid, data->width, data->height,
		(int)data->player.p_x / IMG_SIZE, (int)data->player.p_y / IMG_SIZE,
		&collectibles, &exit_found});
	if (data->total_coins != collectibles)
	{
		printf("Error: The collectibles are not accessible");
		return (0);
	}
	if (!exit_found)
	{
		printf("Error: map is not valid");
		return (0);
	}
	return (1);
}

static int	check_valid_chars(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->grid[i][j] != '1' && data->grid[i][j] != '0' &&
				data->grid[i][j] != 'C' && data->grid[i][j] != 'E' &&
				data->grid[i][j] != 'P' && data->grid[i][j] != 'A')
			{
				printf("Error: Invalid character in map");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	map_checker(t_data *data)
{
	if (!check_valid_chars(data))
		return (0);
	if (!map_bound_checker(data))
	{
		ft_printf("Error: The map is not surrounded by walls");
		clean_up(data);
		return (0);
	}
	if (!count_items(data))
	{
		clean_up(data);
		exit(1);
	}
	if (!bfs_checker(data))
	{
		clean_up(data);
		exit(1);
	}
	return (1);
}
