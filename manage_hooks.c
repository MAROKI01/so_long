#include "so_long_utils.h"

void manage_hooks(t_data *data)
{
	mlx_loop_hook(data->mlx, &keys_function, data);
    mlx_hook(data->win, KeyPress, KeyPressMask, &key_press, data);
    mlx_hook(data->win, KeyRelease, KeyReleaseMask, &key_release, data);
    // mlx_hook(data.win, DestroyNotify, 0, &handle_close, &data);

    mlx_loop(data->mlx);
}