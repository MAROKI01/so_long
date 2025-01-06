#include "so_long_utils.h"

// function to close the window
int close_window(int keycode, void *param)
{
	t_data *data;
	
	data = (t_data *) param;
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(data->mlx,data->win);
		mlx_destroy_display(data->mlx);
		exit(0);
	}
	return (0);
}

int gravity(t_img *ring, t_img *bg, t_data *data)
{
	if (ring->p_y < 650)
	{
		ring->p_y += 1;
		put_img_to_img(bg, ring, 200, ring->p_y);
		mlx_put_image_to_window(data->mlx, data->win, bg->ptr,0, 0);
	}
	return(0);
}

int main(void)
{
    t_data  data;
	t_img 	bg;
    t_img	image;

    // Initialize
    data.mlx = mlx_init();
    if (!data.mlx)
        return (1);
    
    // Create window
    data.win = mlx_new_window(data.mlx, 1000, 650, "Animation");
    if (!data.win)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
        return (1);
	}
    
    // Load map

	bg = new_file_img("textures/lotr_map.xpm", data);
	if (!bg.ptr)
	{
		mlx_destroy_window(data.mlx,data.win);
		mlx_destroy_display(data.mlx);
		free(data.mlx);
        return (1);
	}

	image = new_file_img("textures/ring.xpm", data);
	if (!image.ptr)
    {
		mlx_destroy_image(data.mlx,bg.ptr);
		mlx_destroy_window(data.mlx,data.win);
		mlx_destroy_display(data.mlx);
		free(data.mlx);
        return (1);
	}
	image.p_y = 100;
	image.p_x = 200;
	put_img_to_img(&bg, &image,image.p_x,image.p_y);

	mlx_put_image_to_window(data.mlx, data.win, bg.ptr,10, 10);

	// Hooks 
	mlx_key_hook(data.win, close_window, &data);
	mlx_loop_hook(data.mlx, gravity, &data);
    mlx_loop(data.mlx);
    return (0);
}