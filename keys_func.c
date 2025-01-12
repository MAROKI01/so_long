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

// collision detection
int check_precise_collision(t_data *data, int new_x, int new_y)
{
    // Check the square corners
    int top_left_x = new_x / IMG_SIZE; // also bottom_left_x
    int top_left_y = new_y / IMG_SIZE; // also top_right_y
    int bottom_right_x = (new_x + PLAYER_W) / IMG_SIZE; // also top_right_x
    int bottom_right_y = (new_y + PLAYER_H) / IMG_SIZE; // also bottom_left_y
    
    // Check each corner
    if (data->grid[top_left_y][top_left_x] == '1'
		|| data->grid[bottom_right_y][bottom_right_x] == '1'
		|| data->grid[bottom_right_y][top_left_x] == '1'
		|| data->grid[top_left_y][bottom_right_x] == '1')
		return(1);
	
    return (0);
}

int keys_function(void *param)
{
	t_data *data = (t_data *)param;

	int new_y = data->player.p_y;
	int new_x = data->player.p_x;

	if(data->keys[XK_w])
		new_y -= 1;
	if(data->keys[XK_d])
		new_x += 1;
	if(data->keys[XK_s])
		new_y += 1;
	if(data->keys[XK_a])
		new_x -= 1;

	int check = check_precise_collision(data, new_x, new_y);

	if(data->keys[XK_w] && !check)
		data->player.p_y -= 1;
	if(data->keys[XK_d]&& !check)
		data->player.p_x += 1;
	if(data->keys[XK_s]&& !check)
		data->player.p_y += 1;
	if(data->keys[XK_a]&& !check)
		data->player.p_x -= 1;

	// printf("[%d - ",data->player.p_y);
	// printf("%d]",data->player.p_x);
	// if (data->player.p_x > 0 && data->player.p_y > 0)

	render_map(data);
	return(0);
}
