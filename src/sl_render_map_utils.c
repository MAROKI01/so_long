#include "../include/so_long_utils.h"

void	render_tile(t_data *data, t_img *tile, int x, int y)
{
	if (data && tile)
		put_img_to_img(&data->background, tile, x * data->img_size, y
				* data->img_size);
}

void	render_player(t_data *data, t_img *tile, int x, int y)
{
	if (data && tile)
		put_img_to_img(&data->background, tile, x, y);
}
