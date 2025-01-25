#include "../include/so_long_utils.h"

int key_press(int keycode, t_data *data)
{
	if (keycode >= 0 && keycode < MAX_KEYS)
	{
	if (keycode == XK_Escape)
	{
		clean_up(data);
		exit(0);
	}
	if (keycode == XK_a) 
        data->move_left = 1;
    if (keycode == XK_d) 
        data->move_right = 1;
    if (keycode == XK_w)
        data->move_up = 1;
    if (keycode == XK_s) 
        data->move_down = 1;
	}
	return (0);
}

int which_object_to_detect_coll(t_data *data, char object, float new_x, float new_y)
{
	// Check the square corners
    int top_left_x = new_x / IMG_SIZE; // also bottom_left_x
    int top_left_y = (new_y) / IMG_SIZE; // also top_right_y
    int bottom_right_x = (new_x + PLAYER_W) / IMG_SIZE; // also top_right_x
    int bottom_right_y = (new_y + PLAYER_H) / IMG_SIZE; // also bottom_left_y

	if (data->grid[top_left_y][top_left_x] == object
		|| data->grid[bottom_right_y][bottom_right_x] == object
		|| data->grid[bottom_right_y][top_left_x] == object
		|| data->grid[top_left_y][bottom_right_x] == object)
		return(1);
	
	return(0);
}
void handle_coin_collection(t_data *data, int new_x, int new_y)
{
	int total_coins_number;
	int coin_counter;
	int grid_x;
	int grid_y;

	coin_counter = 0;
	total_coins_number = object_counter(data, 'C');
	grid_y =(new_y + PLAYER_H) / IMG_SIZE;
	grid_x =(new_x + PLAYER_W) / IMG_SIZE;
	if (which_object_to_detect_coll(data, 'C', new_x, new_y))
	{
		coin_counter++;
		data->grid[grid_y][grid_x] = '0';
	}
	if (total_coins_number == coin_counter)
		data->is_exit_open = 1;
}

// collision detection
int check_precise_collision(int keycode, t_data *data)
{
	float new_y = data->player.p_y;
	float new_x = data->player.p_x;

	if(keycode == XK_w)
		new_y -= PLAYER_STEP;
	if(keycode == XK_d)
		new_x += PLAYER_STEP;
	if(keycode == XK_s)
		new_y += PLAYER_STEP;
	if(keycode == XK_a)
		new_x -= PLAYER_STEP;
	
    if (which_object_to_detect_coll(data, '1', new_x, new_y))
		return (wall);

	handle_coin_collection(data,new_x,new_y);
	
	 if (which_object_to_detect_coll(data, 'E', new_x, new_y) && data->is_exit_open)
	 {
		clean_up(data);
		exit(0);
	 }
	
    return (-1);
}

int keys_function(int keycode, void *param)
{
    t_data *data = (t_data *)param;
    int check;

    check = check_precise_collision(keycode, data);

    if (keycode == XK_Escape)
    {
        clean_up(data);
        exit(0);
    }
    if (keycode == XK_w && check != wall)
        data->player.p_y -= PLAYER_STEP;
    if (keycode == XK_d && check != wall)
        data->player.p_x += PLAYER_STEP;
    if (keycode == XK_s && check != wall)
        data->player.p_y += PLAYER_STEP;
    if (keycode == XK_a && check != wall)
        data->player.p_x -= PLAYER_STEP;

    if ((keycode == XK_w || keycode == XK_d || keycode == XK_s || keycode == XK_a) && check != wall)
    {
        data->moves_counter++;
        ft_printf("Move number %d\n", data->moves_counter);
    }

    render_map(data);
    return (0);
}

