#include "../include/so_long_utils.h"

void free_numbers(t_data *data)
{
	if (data->one.ptr)
			mlx_destroy_image(data->mlx, data->one.ptr);
		if (data->two.ptr)
			mlx_destroy_image(data->mlx, data->two.ptr);
		if (data->three.ptr)
			mlx_destroy_image(data->mlx, data->three.ptr);
		if (data->four.ptr)
			mlx_destroy_image(data->mlx, data->four.ptr);
		if (data->five.ptr)
			mlx_destroy_image(data->mlx, data->five.ptr);
		if (data->six.ptr)
			mlx_destroy_image(data->mlx, data->six.ptr);
		if (data->seven.ptr)
			mlx_destroy_image(data->mlx, data->seven.ptr);
		if (data->eight.ptr)
			mlx_destroy_image(data->mlx, data->eight.ptr);
		if (data->nine.ptr)
			mlx_destroy_image(data->mlx, data->nine.ptr);
		if (data->zero.ptr)
			mlx_destroy_image(data->mlx, data->zero.ptr);
		if (data->move_n.ptr)
			mlx_destroy_image(data->mlx, data->move_n.ptr);
}

void free_images(t_data *data)
{
		if (data->front_wall.ptr)
			mlx_destroy_image(data->mlx, data->front_wall.ptr);
		if (data->middle_wall.ptr)
			mlx_destroy_image(data->mlx, data->middle_wall.ptr);
		if (data->floor.ptr)
			mlx_destroy_image(data->mlx, data->floor.ptr);
		if (data->collect.ptr)
			mlx_destroy_image(data->mlx, data->collect.ptr);
		if (data->exit.ptr)
			mlx_destroy_image(data->mlx, data->exit.ptr);
		if (data->exit_open.ptr)
			mlx_destroy_image(data->mlx, data->exit_open.ptr);
		if (data->player.ptr)
			mlx_destroy_image(data->mlx, data->player.ptr);
		if (data->background.ptr)
			mlx_destroy_image(data->mlx, data->background.ptr);
		if (data->enemy.ptr)
			mlx_destroy_image(data->mlx, data->enemy.ptr);
		free_numbers(data);
}


void	clean_up(t_data *data)
{
	int i;

	if (data->grid)
	{
		i = 0;
		while (i < data->height)
			free(data->grid[i++]);
		free(data->grid);
	}
	if (data->mlx)
		free_images(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}