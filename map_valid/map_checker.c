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
// static int rectangular_map_checker(t_data *data)
// {

// }
int map_checker(t_data *data)
{
	// check the bounds of the map
	return(map_bound_checker(data));
	// check if the map rectangular

	// check if we have more than 1 collectibles, 1 exit and 1 player
	// check if the map playable unsing bfs
	// bfs(data.grid,data.width,data.height,(int)data.player.p_x / IMG_SIZE,(int)data.player.p_y / IMG_SIZE,&collectibles ,&exit_found);
}
