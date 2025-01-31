#include "../include/so_long_utils.h"

void free_numbers(t_data *data)
{
	if (data->digits.zero.ptr)
			mlx_destroy_image(data->mlx, data->digits.zero.ptr);
		if (data->digits.two.ptr)
			mlx_destroy_image(data->mlx, data->digits.two.ptr);
		if (data->digits.three.ptr)
			mlx_destroy_image(data->mlx, data->digits.three.ptr);
		if (data->digits.four.ptr)
			mlx_destroy_image(data->mlx, data->digits.four.ptr);
		if (data->digits.five.ptr)
			mlx_destroy_image(data->mlx, data->digits.five.ptr);
		if (data->digits.six.ptr)
			mlx_destroy_image(data->mlx, data->digits.six.ptr);
		if (data->digits.seven.ptr)
			mlx_destroy_image(data->mlx, data->digits.seven.ptr);
		if (data->digits.eight.ptr)
			mlx_destroy_image(data->mlx, data->digits.eight.ptr);
		if (data->digits.nine.ptr)
			mlx_destroy_image(data->mlx, data->digits.nine.ptr);
		if (data->digits.move_n.ptr)
			mlx_destroy_image(data->mlx, data->digits.move_n.ptr);
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
		if (data)
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