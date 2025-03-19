#include "../include/so_long_utils.h"

typedef struct s_collision_box
{
	int		offset_left;
	int		offset_right;
	int		offset_top;
	int		offset_bottom;
	int		col_x;
	int		col_y;
	int		col_w;
	int		col_h;
	int		center_y;
	int		center_x;
	int		sample_step;
}			t_collision_box;

int	key_press(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == XK_Escape)
	{
		clean_up(data);
		exit(0);
	}
	if (keycode >= 0 && keycode < MAX_KEYS)
	{
		data->keys[keycode] = 1;
	}
	return (0);
}
// keyrealease
int	key_release(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode >= 0 && keycode < MAX_KEYS)
	{
		data->keys[keycode] = 0;
	}
	return (0);
}
static int	check_cell(t_data *data, char object, int x, int y)
{
	int	grid_x;
	int	grid_y;

	grid_x = x / IMG_SIZE;
	grid_y = y / IMG_SIZE;
	if (grid_y < 0 || grid_y >= data->height || grid_x < 0 ||
		grid_x >= data->width)
		return (0);
	if (data->grid[grid_y][grid_x] == object)
		return (1);
	return (0);
}
static int	is_colliding_with_object(t_data *data, char object, int new_x,
		int new_y)
{
	t_collision_box	box;
	int				x;
	int				y;

	box.offset_left = 41;
	box.offset_right = 36;
	box.offset_top = 40;
	box.offset_bottom = 52;
	box.col_x = new_x + box.offset_left;
	box.col_y = new_y + box.offset_top;
	box.col_w = PLAYER_W - (box.offset_left + box.offset_right);
	box.sample_step = 4;
	y = box.col_y;
	while (y < box.col_y + PLAYER_H - (box.offset_top + box.offset_bottom))
	{
		x = box.col_x;
		while (x < box.col_x + box.col_w)
		{
			if (check_cell(data, object, x, y))
				return (1);
			x += box.sample_step;
		}
		y += box.sample_step;
	}
	return (0);
}

static void	handle_coin_collection(t_data *data, int new_x, int new_y)
{
	t_collision_box	box;
	int				grid_y;
	int				grid_x;

	box.offset_left = 80;
	box.offset_right = 36;
	box.offset_top = 40;
	box.offset_bottom = 52;
	box.center_x = new_x + (box.offset_left + box.offset_right) / 2;
	box.center_y = new_y + (box.offset_top + box.offset_bottom) / 2;
	grid_x = box.center_x / IMG_SIZE;
	grid_y = box.center_y / IMG_SIZE;
	if (data->grid[grid_y][grid_x] == 'C')
	{
		data->coin_counter++;
		data->grid[grid_y][grid_x] = '0';
	}
	if (data->total_coins == data->coin_counter)
		data->is_exit_open = 1;
}

static int	check_precise_collision(t_data *data)
{
	int	new_y;
	int	new_x;

	new_y = data->player.p_y;
	new_x = data->player.p_x;
	if (data->keys[XK_w])
		new_y -= PLAYER_STEP;
	if (data->keys[XK_d])
		new_x += PLAYER_STEP;
	if (data->keys[XK_s])
		new_y += PLAYER_STEP;
	if (data->keys[XK_a])
		new_x -= PLAYER_STEP;
	if (is_colliding_with_object(data, '1', new_x, new_y))
		return (0);
	handle_coin_collection(data, new_x, new_y);
	if ((is_colliding_with_object(data, 'E', new_x, new_y)
			&& data->is_exit_open))
	{
		clean_up(data);
		exit(0);
	}
	return (-1);
}

static void	update_movement_keys(t_data *data, int check)
{
	if (data->keys[XK_w] && check != 0)
	{
		data->player.p_y -= PLAYER_STEP;
		data->player.direction = UP;
		data->current_sprite = data->sprites.up;
	}
	if (data->keys[XK_s] && check != 0)
	{
		data->player.p_y += PLAYER_STEP;
		data->player.direction = DOWN;
		data->current_sprite = data->sprites.down;
	}
	if (data->keys[XK_d] && check != 0)
	{
		data->player.p_x += PLAYER_STEP;
		data->player.direction = RIGHT;
		data->current_sprite = data->sprites.right;
	}
	if (data->keys[XK_a] && check != 0)
	{
		data->player.p_x -= PLAYER_STEP;
		data->player.direction = LEFT;
		data->current_sprite = data->sprites.left;
	}
}

static void	update_idle_state(t_data *data)
{
	if (!data->keys[XK_w] && !data->keys[XK_d] &&
		!data->keys[XK_s] && !data->keys[XK_a])
	{
		data->player.direction = IDLE;
		data->current_sprite = data->sprites.idle;
	}
}

static void	update_moves_counter(t_data *data, int check)
{
	if ((data->keys[XK_w] || data->keys[XK_d] ||
			data->keys[XK_s] || data->keys[XK_a]) &&
		check != 0)
	{
		data->moves_counter++;
		ft_printf("Move number %d\n", data->moves_counter);
	}
}

int	keys_function(void *param)
{
	t_data	*data;
	int		check;

	data = (t_data *)param;
	static int move_delay = 0; // simple counter for movement delay
	check = check_precise_collision(data);
	if (++move_delay < 10000) // adjust delay frames here
		return (0);
	move_delay = 0;
	update_movement_keys(data, check);
	update_idle_state(data);
	update_moves_counter(data, check);
	return (0);
}
