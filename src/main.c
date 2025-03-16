#include "../include/so_long_utils.h"

static int init_map(t_data *data, char *data_file)
{
    if (!read_map(data, data_file))
    {
        ft_printf("Error: failed to read map.");
        clean_up(data);
        return (0);
    }
    return (1);
}

static int init_player_and_checker(t_data *data)
{
    init_player_pos(data);
    if (!map_checker(data))
        return (0);
    return (1);
}

static int create_game_window(t_data *data)
{
    data->win = mlx_new_window(data->mlx,
        data->width * IMG_SIZE, data->height * IMG_SIZE, "So long");
    if (!data->win)
    {
        clean_up(data);
        return (0);
    }
    data->window.win_ptr = data->win;
    data->window.mlx_ptr = data->mlx;
    data->window.width = data->width;
    data->window.height = data->height;
    return (1);
}

static void setup_game(t_data *data)
{
    load_textures(data);
    init_player_pos(data);
    render_map(data);
    manage_hooks(data);
}

int main(int ac, char **av)
{
	t_data data;
	(void)ac;
	if (ac != 2)
	{
		ft_printf("Error: Please enter a single map.");
		return (1);
	}
    ft_memset(&data, 0, sizeof(t_data));
    data.mlx = mlx_init();
    if (!data.mlx)
        return (0);
    if (!init_map(&data, av[1]))
        return (0);
    if (!init_player_and_checker(&data))
        return (0);
    if (!create_game_window(&data))
        return (0);
    setup_game(&data);
	return (0);
}
