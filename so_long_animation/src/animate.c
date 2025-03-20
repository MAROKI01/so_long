#include "../../include/so_long_utils.h"
#include "../include/libft.h"
#include "../include/sprite.h"
#include "../include/utils.h"

static t_list	*get_animation_list(t_data *data, int object)
{
	if (object == 'C')
		return (data->sprites.coin.animations);
	else if (object == 'A')
		return (data->sprites.enemy.animations);
	return (NULL);
}

static void	render_object_frame(t_data *data, t_img *img, int object)
{
	int	row;
	int	col;

	row = 0;
	while (row < data->height)
	{
		col = 0;
		while (col < data->width)
		{
			if (data->grid[row][col] == object)
				render_player(data, img, col * IMG_SIZE, row * IMG_SIZE);
			col++;
		}
		row++;
	}
}

static void	process_animation_frame(t_data *data, t_animation *a, int object)
{
	t_img	*img;

	a->_tmp_delay = 0;
	a->current_frame_num++;
	a->current_frame_num %= ft_lstsize(a->frames);
	img = (t_img *)ft_lstget_anim(a->frames, a->current_frame_num)->content;
	render_object_frame(data, img, object);
	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr,
			data->background.ptr, 0, 0);
}

static int	animate_object(void *ptr, int object)
{
	t_data		*data;
	t_list		*animation_node;
	t_animation	*a;

	data = (t_data *)ptr;
	animation_node = get_animation_list(data, object);
	while (animation_node)
	{
		a = (t_animation *)animation_node->content;
		if (a->_tmp_delay++ == a->delay)
			process_animation_frame(data, a, object);
		animation_node = animation_node->next;
	}
	return (0);
}

static void	process_player_animation_frame(t_data *data, t_animation *a)
{
	t_img	*img;

	a->_tmp_delay = 0;
	a->current_frame_num++;
	a->current_frame_num %= ft_lstsize(a->frames);
	img = (t_img *)ft_lstget_anim(a->frames, a->current_frame_num)->content;
	render_map(data);
	render_player(data, img, data->player.p_x, data->player.p_y);
	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr,
			data->background.ptr, 0, 0);
}

int	update_animations(void *ptr)
{
	t_data		*data;
	t_list		*animation_node;
	t_animation	*a;

	data = (t_data *)ptr;
	animation_node = data->current_sprite.animations;
	while (animation_node)
	{
		a = (t_animation *)animation_node->content;
		if (a->_tmp_delay++ == a->delay)
			process_player_animation_frame(data, a);
		animation_node = animation_node->next;
	}
	animate_object(data, 'C');
	return (0);
}

t_sprite	init_sprite(t_data *data, char *file_path, int frames,
		t_sprite_slice slice)
{
	t_win			tutorial;
	t_sprite		s1;
	t_sprite_slice	slice1;

	tutorial = data->window;
	s1 = new_sprite_anim("sprite", file_path, &tutorial);
	if (!s1.sprite_img.ptr)
	{
		destroy_sprite_anim(s1);
		destroy_window_anim(tutorial);
		return (s1);
	}
	slice1 = (t_sprite_slice)slice;
	ft_lstadd_back(&s1.animations, ft_lstnew(slice_sprite_anim(data, s1, slice1,
					frames, 10000, PLAYER)));
	printf("Sprite %s [%d %d], loaded %d animations\n", s1.name, s1.width,
			s1.height, ft_lstsize(s1.animations));
	return (s1);
}

int	intialize_animations(t_data *data)
{
	t_sprite_slice	player_slice;
	t_sprite_slice	object_slice;

	player_slice = (t_sprite_slice){0, 0, 109, 109};
	object_slice = (t_sprite_slice){0, 0, 32, 32};
	data->player.direction = LEFT;
	data->sprites.right = init_sprite(data, "textures/sprites/sprite_right.xpm",
			11, player_slice);
	data->sprites.left = init_sprite(data, "textures/sprites/sprite_left.xpm",
			11, player_slice);
	data->sprites.up = init_sprite(data, "textures/sprites/sprite_up.xpm", 11,
			player_slice);
	data->sprites.down = init_sprite(data, "textures/sprites/sprite_down.xpm",
			11, player_slice);
	data->sprites.idle = init_sprite(data, "textures/sprites/sprite_idle.xpm",
			25, player_slice);
	data->sprites.coin = init_sprite(data, "textures/sprites/coin.xpm", 9,
			object_slice);
	return (0);
}

int	animate(t_data *data)
{
	if (!data->window.win_ptr)
		return (2);
	move_enemies(data);
	keys_function(data);
	update_animations(data);
	return (0);
}
