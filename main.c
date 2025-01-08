#include "so_long_utils.h"

// function to close the window
int clean_up(void *param)
{
	t_data *data;
	
	data = (t_data *) param;
	if (data->image.ptr)
		mlx_destroy_image(data->mlx, data->image.ptr);
	
	if(data->bg.ptr)
		mlx_destroy_image(data->mlx, data->bg.ptr);

	if(data->win)
		mlx_destroy_window(data->mlx, data->win);
	
	if(data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	return (0);
}

int gravity(t_data *data)
{
	if (data->image.p_y < 650)
	{
		data->image.p_y += 1;
		
	}
	return(0);
}

// keypress 
int key_press(int keycode, void *param)
{
	t_data *data = (t_data *)param;

	if (keycode >= 0 && keycode <= 256)
		data->keys[keycode] = 1;
	return (0);
}
// keyrealease
int key_release(int keycode, void *param)
{
	t_data *data = (t_data *)param;

	if (keycode >= 0 && keycode <= 256)
		data->keys[keycode] = 0;
	return (0);
}

int keys_function(void *param)
{
	t_data *data = (t_data *)param;

	// if (data->keys[XK_Escape])
	// {
	// 	clean_up(data);
	// 	exit(0);
	// }
	if(data->keys[XK_w])
		data->image.p_y -= 2;
	if(data->keys[XK_d])
		data->image.p_x += 2;
	if(data->keys[XK_s])
		data->image.p_y += 2;
	if(data->keys[XK_a])
		data->image.p_x -= 2;

	// if (data->image.p_y < 600)
	// 	gravity(data);
	
	if (data->bg.ptr)
		mlx_destroy_image(data->mlx, data->bg.ptr);

	data->bg = new_file_img("textures/lotr_map.xpm", *data);

	put_img_to_img(&data->bg, &data->image, data->image.p_x, data->image.p_y);
	mlx_put_image_to_window(data->mlx, data->win, data->bg.ptr,0, 0);
	return(0);
}
int main(void)
{
    t_data  data;

    // Initialize
    data.mlx = mlx_init();
    if (!data.mlx)
        return (1);
    
    // Create window
    data.win = mlx_new_window(data.mlx, 1000, 650, "Animation");
    if (!data.win)
	{
		clean_up(&data);
        return (1);
	}
    
    // Load map

	data.bg = new_file_img("textures/lotr_map.xpm", data);
	if (!data.bg.ptr)
	{
		clean_up(&data);
        return (1);
	}

	data.image = new_file_img("textures/ring.xpm", data);
	if (!data.image.ptr)
    {
		clean_up(&data);
        return (1);
	}

	data.image.p_y = 100;
	data.image.p_x = 200;

	ft_memset(data.keys, 0, sizeof(data.keys));

	printf("%d", data.keys[55]);
	// Hooks
	mlx_hook(data.win, KeyPress, KeyPressMask, key_press, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, key_release, &data);
	mlx_loop_hook(data.mlx, keys_function, &data);
    mlx_loop(data.mlx);
    return (0);
}