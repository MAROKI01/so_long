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
		data->image.p_y -= 2;
	if(data->keys[XK_d])
		data->image.p_x += 2;
	if(data->keys[XK_s])
		data->image.p_y += 2;
	if(data->keys[XK_a])
		data->image.p_x -= 2;

	if (data->image.p_y < 600)
	{
		gravity(data);
	
		if (data->bg.ptr)
			mlx_destroy_image(data->mlx, data->bg.ptr);

		data->bg = new_file_img("textures/lotr_map.xpm", *data);

		put_img_to_img(&data->bg, &data->image, data->image.p_x, data->image.p_y);
		mlx_put_image_to_window(data->mlx, data->win, data->bg.ptr,0, 0);
	}
	return(0);
}