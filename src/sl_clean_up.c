#include "../include/so_long_utils.h"
#include "../so_long_animation/include/animation.h"

void	free_numbers(t_data *data)
{
	if (data->digits.zero.ptr)
		mlx_destroy_image(data->mlx, data->digits.zero.ptr);
	if (data->digits.one.ptr)
		mlx_destroy_image(data->mlx, data->digits.one.ptr);
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

void	free_sprite_names_and_paths(t_sprite *sprite)
{
	if (sprite->name)
	{
		free(sprite->name);
		sprite->name = NULL;
	}
	if (sprite->file_path)
	{
		free(sprite->file_path);
		sprite->file_path = NULL;
	}
}

void	free_sprites(t_data *data)
{
	if (data->sprites.up.sprite_img.ptr)
		mlx_destroy_image(data->mlx, data->sprites.up.sprite_img.ptr);
	free_sprite_names_and_paths(&data->sprites.up);
	if (data->sprites.down.sprite_img.ptr)
		mlx_destroy_image(data->mlx, data->sprites.down.sprite_img.ptr);
	free_sprite_names_and_paths(&data->sprites.down);
	if (data->sprites.left.sprite_img.ptr)
		mlx_destroy_image(data->mlx, data->sprites.left.sprite_img.ptr);
	free_sprite_names_and_paths(&data->sprites.left);
	if (data->sprites.right.sprite_img.ptr)
		mlx_destroy_image(data->mlx, data->sprites.right.sprite_img.ptr);
	free_sprite_names_and_paths(&data->sprites.right);
	if (data->sprites.idle.sprite_img.ptr)
		mlx_destroy_image(data->mlx, data->sprites.idle.sprite_img.ptr);
	free_sprite_names_and_paths(&data->sprites.idle);
	if (data->sprites.coin.sprite_img.ptr)
		mlx_destroy_image(data->mlx, data->sprites.coin.sprite_img.ptr);
	free_sprite_names_and_paths(&data->sprites.coin);
	if (data->sprites.enemy.sprite_img.ptr)
		mlx_destroy_image(data->mlx, data->sprites.enemy.sprite_img.ptr);
	free_sprite_names_and_paths(&data->sprites.enemy);
}

void	free_images(t_data *data)
{
	if (data->front_wall.ptr)
		mlx_destroy_image(data->mlx, data->front_wall.ptr);
	if (data->middle_wall.ptr)
		mlx_destroy_image(data->mlx, data->middle_wall.ptr);
	if (data->floor.ptr)
		mlx_destroy_image(data->mlx, data->floor.ptr);
	if (data->exit.ptr)
		mlx_destroy_image(data->mlx, data->exit.ptr);
	if (data->exit_open.ptr)
		mlx_destroy_image(data->mlx, data->exit_open.ptr);
	if (data->shadow.ptr)
		mlx_destroy_image(data->mlx, data->shadow.ptr);
	if (data->background.ptr)
		mlx_destroy_image(data->mlx, data->background.ptr);
	if (data->enemy.ptr)
		mlx_destroy_image(data->mlx, data->enemy.ptr);
	if (data)
		free_numbers(data);
	if (data->enemies)
		free(data->enemies);
}

void	free_frames(t_list *frames)
{
	t_list	*tmp;

	while (frames)
	{
		tmp = frames->next;
		if (((t_img *)frames->content)->ptr)
			mlx_destroy_image(((t_img *)frames->content)->win.mlx_ptr,
								((t_img *)frames->content)->ptr);
		free(frames->content);
		free(frames);
		frames = tmp;
	}
}

void	free_animations(t_list *animations)
{
	t_list	*tmp;

	while (animations)
	{
		tmp = animations->next;
		free_frames(((t_animation *)animations->content)->frames);
		free(animations->content);
		free(animations);
		animations = tmp;
	}
}

void	free_animation(t_data *data)
{
	free_animations(data->sprites.up.animations);
	free_animations(data->sprites.down.animations);
	free_animations(data->sprites.left.animations);
	free_animations(data->sprites.right.animations);
	free_animations(data->sprites.idle.animations);
	free_animations(data->sprites.coin.animations);
	free_animations(data->sprites.enemy.animations);
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
	if (data->mlx)
		free_animation(data);
	if (data->mlx)
		free_sprites(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}

