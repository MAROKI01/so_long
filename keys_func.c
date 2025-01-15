#include "so_long_utils.h"

// keypress 
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
	}
	return (0);
}
// keyrealease
int key_release(int keycode, void *param)
{
	t_data *data = (t_data *)param;

	if (keycode >= 0 && keycode < MAX_KEYS)
		data->keys[keycode] = 0;
	return (0);
}
int which_object_to_detect_coll(t_data *data, char object, int new_x, int new_y)
{
	// Check the square corners
    int top_left_x = new_x / IMG_SIZE; // also bottom_left_x
    int top_left_y = new_y / IMG_SIZE; // also top_right_y
    int bottom_right_x = (new_x + PLAYER_W) / IMG_SIZE; // also top_right_x
    int bottom_right_y = (new_y + PLAYER_H) / IMG_SIZE; // also bottom_left_y

	if (data->grid[top_left_y][top_left_x] == object
		|| data->grid[bottom_right_y][bottom_right_x] == object
		|| data->grid[bottom_right_y][top_left_x] == object
		|| data->grid[top_left_y][bottom_right_x] == object)
		return(1);
	
	return(0);
}
// collision detection
int check_precise_collision(t_data *data)
{
	int new_y = data->player.p_y;
	int new_x = data->player.p_x;
	int coins_count = 0;
	int total_coins_number = object_counter(data, 'C');

	if(data->keys[XK_w])
		new_y -= PLAYER_SPEED;
	if(data->keys[XK_d])
		new_x += PLAYER_SPEED;
	if(data->keys[XK_s])
		new_y += PLAYER_SPEED;
	if(data->keys[XK_a])
		new_x -= PLAYER_SPEED;

    if (which_object_to_detect_coll(data, '1', new_x, new_y))
		return (wall);

	 if (which_object_to_detect_coll(data, 'C', new_x, new_y))
	 {
			data->grid[(new_y + PLAYER_H) / IMG_SIZE][ (new_x + PLAYER_W)/ IMG_SIZE] = '0';
			coins_count++;
	 }
	
	 if (which_object_to_detect_coll(data, 'E', new_x, new_y) && (coins_count == total_coins_number))
	 {
		clean_up(data);
		exit(0);
	 }
	
    return (-1);
}

int keys_function(void *param)
{
	t_data *data = (t_data *)param;

	int check = check_precise_collision(data);

	if(data->keys[XK_w] && check != wall)
		data->player.p_y -= PLAYER_SPEED;
	if(data->keys[XK_d] && check != wall)
		data->player.p_x += PLAYER_SPEED;
	if(data->keys[XK_s] && check != wall)
		data->player.p_y += PLAYER_SPEED;
	if(data->keys[XK_a] && check != wall)
		data->player.p_x -= PLAYER_SPEED;

	render_map(data);
	return(0);
}
