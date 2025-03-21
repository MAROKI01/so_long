/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 00:30:15 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/21 10:01:02 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_utils.h"

static int	count_map_lines(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	height = 0;
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

static int	validate_map_dimensions(t_data *data, char *line, int index)
{
	if (index == 0)
	{
		data->width = ft_strlen(line) - 1;
		return (1);
	}
	return (!check_line_length(line, data->width));
}

static char	**allocate_grid(int height)
{
	char	**grid;
	int		i;

	grid = malloc(sizeof(char *) * (height + 1));
	if (!grid)
		return (NULL);
	i = 0;
	while (i <= height)
	{
		grid[i++] = NULL;
	}
	return (grid);
}

static int	populate_grid(t_data *data, char *filename)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	i = 0;
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line && i < data->height)
	{
		if (!validate_map_dimensions(data, line, i))
		{
			close(fd);
			free(line);
			clean_up(data);
			exit(1);
		}
		data->grid[i++] = line;
		line = get_next_line(fd);
	}
	free(line);
	data->grid[i] = NULL;
	close(fd);
	return (1);
}

int	read_map(t_data *data, char *filename)
{
	data->height = count_map_lines(filename);
	if (data->height <= 0)
		return (0);
	data->grid = allocate_grid(data->height);
	if (!data->grid)
		return (0);
	return (populate_grid(data, filename));
}
