#include "so_long_utils.h"


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
	// Hooks
	mlx_hook(data.win, KeyPress, KeyPressMask, key_press, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, key_release, &data);
	mlx_loop_hook(data.mlx, keys_function, &data);
    mlx_loop(data.mlx);
    return (0);
}