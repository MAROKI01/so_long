/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 03:06:40 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/20 03:13:55 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_utils.h"

static void	init_bfs(t_bfs *data, char **map, int width, int height)
{
	int	i;

	i = 0;
	data->queue = malloc(sizeof(t_vertex) * (width * height));
	data->was_visited = malloc(sizeof(int *) * height);
	while (i < height)
	{
		data->was_visited[i] = malloc(sizeof(int) * width);
		ft_memset(data->was_visited[i], 0, sizeof(int) * width);
		i++;
	}
	data->rear = 0;
	data->front = 0;
	data->width = width;
	data->height = height;
	data->map = map;
}

static void	cleanup_bfs(t_bfs *data)
{
	int	i;

	i = 0;
	free(data->queue);
	while (i < data->height)
	{
		free(data->was_visited[i]);
		i++;
	}
	free(data->was_visited);
}

static void	check_current_cell(t_vertex current, char **map, int *collectibles,
		int *exit_found)
{
	if (map[current.y][current.x] == 'C')
		(*collectibles)++;
	if (map[current.y][current.x] == 'E')
		*exit_found = 1;
}

static void	get_neighbors(int neighbors[4][2])
{
	neighbors[0][0] = -1;
	neighbors[0][1] = 0;
	neighbors[1][0] = 0;
	neighbors[1][1] = -1;
	neighbors[2][0] = 1;
	neighbors[2][1] = 0;
	neighbors[3][0] = 0;
	neighbors[3][1] = 1;
}

static void	explore_neighbors(t_bfs *data, t_vertex current)
{
	int	neighbors[4][2];
	int	i;
	int	nx;
	int	ny;

	get_neighbors(neighbors);
	i = 0;
	while (i < 4)
	{
		nx = current.x + neighbors[i][0];
		ny = current.y + neighbors[i][1];
		if (nx >= 0 && ny >= 0 && nx < data->width && ny < data->height
			&& !data->was_visited[ny][nx] && data->map[ny][nx] != '1')
		{
			data->was_visited[ny][nx] = 1;
			data->queue[data->front++] = (t_vertex){nx, ny};
		}
		i++;
	}
}

void	bfs(t_bfs_params params)
{
	t_bfs		data;
	t_vertex	current;

	if (!params.map || !params.collectibles || !params.exit_found
		|| !(params.p_x >= 0 && params.p_x < params.width) || !(params.p_y >= 0
			&& params.p_y < params.height))
		return ;
	init_bfs(&data, params.map, params.width, params.height);
	*(params.collectibles) = 0;
	*(params.exit_found) = 0;
	data.queue[data.front++] = (t_vertex){params.p_x, params.p_y};
	data.was_visited[params.p_y][params.p_x] = 1;
	while (data.front > data.rear)
	{
		current = data.queue[data.rear++];
		check_current_cell(current, params.map, params.collectibles,
		params.exit_found);
		explore_neighbors(&data, current);
	}
	cleanup_bfs(&data);
}
