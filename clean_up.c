#include "so_long_utils.h"

void clean_up(t_data *data)
{
	int i;

    if (data->grid)
    {
        i = 0;
        while (i < data->height)
            free(data->grid[i++]);
        free(data->grid);
    }
    
    // Free all images
    if (data->wall.ptr)
        mlx_destroy_image(data->mlx, data->wall.ptr);
    if (data->floor.ptr)
        mlx_destroy_image(data->mlx, data->floor.ptr);
    if (data->collect.ptr)
        mlx_destroy_image(data->mlx, data->collect.ptr);
    if (data->exit.ptr)
        mlx_destroy_image(data->mlx, data->exit.ptr);
    if (data->player.ptr)
        mlx_destroy_image(data->mlx, data->player.ptr);
    if (data->background.ptr)
        mlx_destroy_image(data->mlx, data->background.ptr);
        
    if (data->win)
        mlx_destroy_window(data->mlx, data->win);
    if (data->mlx)
    {
        mlx_destroy_display(data->mlx);
        free(data->mlx);
    }
}