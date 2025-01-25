#include "../include/so_long_utils.h"

static int handle_close(t_data *data)
{
	clean_up(data);
	exit(0);
	return (0);
}
void manage_hooks(t_data *data)
{

    mlx_hook(data->win, KeyPress, KeyPressMask, &key_press, data);
	mlx_key_hook(data->win, &keys_function, data);
    mlx_hook(data->win, DestroyNotify, 0, &handle_close, data);
    mlx_loop(data->mlx);
}
