#include "../include/so_long_utils.h"

int key_press(int keycode, void *param)
{
	t_data *data = (t_data *)param;

	if (keycode == XK_Escape)
	{
		clean_up(data);
		exit(0);
	}
	if (keycode >= 0 && keycode < MAX_KEYS)
	{
	data->keys[keycode] = 1;
    // printf("Key %d pressed : %d\n", keycode,data->keys[keycode]); // Debug output
	}
	return (0);
}
// keyrealease
int key_release(int keycode, void *param)
{
    t_data *data = (t_data *)param;
	
    if (keycode >= 0 && keycode < MAX_KEYS)
    {
        data->keys[keycode] = 0;
        // printf("Key %d released : %d\n", keycode,data->keys[keycode]); // Debug output
    }
    return 0;
}

static int which_object_to_detect_coll(t_data *data, char object, int new_x, int new_y)
{
    int top_left_x = new_x / IMG_SIZE; 
    int top_left_y = (new_y) / IMG_SIZE; 
    int bottom_right_x = (new_x + PLAYER_W) / IMG_SIZE; 
    int bottom_right_y = (new_y + PLAYER_H) / IMG_SIZE; 

	if (data->grid[top_left_y][top_left_x] == object
		|| data->grid[bottom_right_y][bottom_right_x] == object
		|| data->grid[top_left_y][bottom_right_x] == object
		|| data->grid[bottom_right_y][top_left_x] == object
		)
		return(1);
	
	return(0);
}

static void handle_coin_collection(t_data *data, int new_x, int new_y)
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

static int check_precise_collision(t_data *data)
{
	int new_y;
	int new_x;

	new_y = data->player.p_y;
	new_x = data->player.p_x;
	if(data->keys[XK_w])
		new_y -= PLAYER_STEP;
	if(data->keys[XK_d])
		new_x += PLAYER_STEP;
	if(data->keys[XK_s])
		new_y += PLAYER_STEP;
	if(data->keys[XK_a])
		new_x -= PLAYER_STEP;
    if (which_object_to_detect_coll(data, '1', new_x, new_y))
		return (0);
	handle_coin_collection(data,new_x,new_y);
	 if ((which_object_to_detect_coll(data, 'E', new_x, new_y) && data->is_exit_open)
	 	|| which_object_to_detect_coll(data, 'A', new_x, new_y))
	 {
		clean_up(data);
		exit(0);
	 }
    return (-1);
}

int keys_function(void *param)
{
    t_data *data = (t_data *)param;
    int check;

    check = check_precise_collision(data);
    // if (keycode == XK_Escape)
    // {
    //     clean_up(data);
    //     exit(0);
    // }
	// printf("up : %d, down : %d, left : %d, right : %d\n", data->keys[XK_w], data->keys[XK_d],data->keys[XK_s],data->keys[XK_a]);
    if (data->keys[XK_w] && check != 0)
        data->player.p_y -= PLAYER_STEP;
    if (data->keys[XK_s] && check != 0)
        data->player.p_y += PLAYER_STEP;
    if (data->keys[XK_d] && check != 0)
        data->player.p_x += PLAYER_STEP;
    if (data->keys[XK_a] && check != 0)
        data->player.p_x -= PLAYER_STEP;
    if ((data->keys[XK_w] || data->keys[XK_d] || data->keys[XK_s] || data->keys[XK_a]) && check != 0)
    {
        data->moves_counter++;
        ft_printf("Move number %d\n", data->moves_counter);
    }
    render_map(data);
	// animate(data);
    return (0);
}

