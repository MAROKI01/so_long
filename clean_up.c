#include "so_long_utils.h"

void clean_up(void *param)
{
	t_data *data;
	
	data = (t_data *) param;

	if (data->image.ptr)
		mlx_destroy_image(data->mlx, data->image.ptr);
	
	if(data->bg.ptr)
		mlx_destroy_image(data->mlx, data->bg.ptr);

	if(data->win)
		mlx_destroy_window(data->mlx, data->win);
	
	if(data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}