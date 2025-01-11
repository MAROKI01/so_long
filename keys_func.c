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

int keys_function(void *param)
{
	t_data *data = (t_data *)param;

	if(data->keys[XK_w])
		data->player.p_y -= 2;
	if(data->keys[XK_d])
		data->player.p_x += 2;
	if(data->keys[XK_s])
		data->player.p_y += 2;
	if(data->keys[XK_a])
		data->player.p_x -= 2;

	printf("[%d - ",data->player.p_y);
	printf("%d]",data->player.p_x);
	if (data->player.p_x > 0 && data->player.p_y > 0)
		render_tile(data, &data->player, data->player.p_x, data->player.p_y);

	render_map(data);
	return(0);
}
