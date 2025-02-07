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

static int is_colliding_with_object(t_data *data, char object, int new_x, int new_y)
{
    // These offsets remove extra margins in the image:
    int offset_left = 41;
    int offset_right = 36;
    int offset_top = 40;
    int offset_bottom = 52;
    
    // Define the collision box within the sprite:
    int col_x = new_x + offset_left;
    int col_y = new_y + offset_top;
    int col_w = PLAYER_W - (offset_left + offset_right);
    int col_h = PLAYER_H - (offset_top + offset_bottom);
    
    // Choose a small step to sample across the entire collision box.
    int sample_step = 4;  // Adjust based on precision and performance

    // Loop over the collision box region.
    for (int y = col_y; y < col_y + col_h; y += sample_step)
    {
        for (int x = col_x; x < col_x + col_w; x += sample_step)
        {
            int grid_x = x / IMG_SIZE;
            int grid_y = y / IMG_SIZE;
            
            // Check if indices are within grid bounds.
            if (grid_y < 0 || grid_y >= data->height ||
                grid_x < 0 || grid_x >= data->width)
                continue;
            
            if (data->grid[grid_y][grid_x] == object)
                return 1;
        }
    }
    return 0;
}

static void handle_coin_collection(t_data *data, int new_x, int new_y)
{
    // Offsets for the player's collision area
    int offset_left = 80;
    int offset_right = 36;
    int offset_top = 40;
    int offset_bottom = 52;

    // Compute player's center point using the offsets
    int center_x = new_x + (offset_left + offset_right) / 2;
    int center_y = new_y + (offset_top + offset_bottom) / 2;
    
    // Calculate grid indices based on center position
    int grid_x = center_x / IMG_SIZE;
    int grid_y = center_y / IMG_SIZE;

    // Only count the coin if it hasn't been collected yet.
    if (data->grid[grid_y][grid_x] == 'C')
    {
        data->coin_counter++;
        data->grid[grid_y][grid_x] = '0';
    }
    if (data->total_coins == data->coin_counter)
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
    if (is_colliding_with_object(data, '1', new_x, new_y))
		return (0);
	handle_coin_collection(data,new_x,new_y);
	 if ((is_colliding_with_object(data, 'E', new_x, new_y) && data->is_exit_open)
	 	|| is_colliding_with_object(data, 'A', new_x, new_y))
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
    static int move_delay = 0; // simple counter for movement delay

    check = check_precise_collision(data);

	if (++move_delay < 10000) // adjust 10 to the desired delay frames
        return (0);
    move_delay = 0;

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
    if (!data->keys[XK_w] && !data->keys[XK_d] && !data->keys[XK_s] && !data->keys[XK_a])
    {
        data->player.direction = IDLE;
        data->current_sprite = data->sprites.idle;
    }
    if ((data->keys[XK_w] || data->keys[XK_d] || data->keys[XK_s] || data->keys[XK_a]) && check != 0)
    {
        data->moves_counter++;
        ft_printf("Move number %d\n", data->moves_counter);
    }
    // render_map(data);
	// animate(data);
	// mlx_loop(data->mlx);
    return (0);
}

