#include "../include/so_long_utils.h"

static int map_bound_checker(t_data *data)
{
	int i;

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

static int count_items(t_data *data)
{
	int exit;
	int player;

	data->total_coins = object_counter(data, 'C');
	exit = object_counter(data, 'E');
	player = object_counter(data, 'P');
	if (data->total_coins == 0)
	{
		printf("Error: Too few coins");
		return(0);
	}
	if (exit > 1 || exit == 0)
	{
		printf("Error: Required one exit");
		return(0);
	}
	if (player == 0 || player > 1)
	{
		printf("Error: Required one player");
		return(0);
	}
	return(1);
}

static int bfs_checker(t_data *data)
{
	int collectibles;
	int exit_found;

	bfs(data->grid,data->width,data->height,(int)data->player.p_x / IMG_SIZE,(int)data->player.p_y / IMG_SIZE,&collectibles ,&exit_found);

	if(data->total_coins != collectibles)
	{
		printf("Error: The collectibles are not accessible");
		return(0);
	}

	if (!exit_found)
	{
		printf("Error: The exit is not accessible");
		return(0);
	}
	return(1);
}

int map_checker(t_data *data)
{
	if (!map_bound_checker(data))
	{
		ft_printf("Error: The map is not surrounded by walls");
		return(0);
	}
	if (!count_items(data))
		return(0);
	
	if (!bfs_checker(data))
		return(0);

	return(1);
}
