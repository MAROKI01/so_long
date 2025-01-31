#include "../include/so_long_utils.h"

int init_game(char *data_file)
{
    t_data   data;

    ft_memset(&data, 0, sizeof(t_data));
    data.mlx = mlx_init();
    if (!data.mlx)
        return (0);
    if (!read_map(&data, data_file))
    {
		ft_printf("Error: failed to read map.");
        clean_up(&data);
        return (0);
    }
	init_player_pos(&data);
	if (!map_checker(&data))
		return(1);
    data.win = mlx_new_window(data.mlx, 
        data.width * IMG_SIZE, data.height * IMG_SIZE, "So long");
    if (!data.win)
    {
        clean_up(&data);
        return (0);
    }
    load_textures(&data);
	init_player_pos(&data);
    render_map(&data);
   	manage_hooks(&data);
    return (1);
}

int main(int ac, char **av)
{
	(void)ac;
	if (ac != 2)
	{
		ft_printf("Error: Please enter a single map.");
		return (1);
	}
	init_game(av[1]);
	return (0);
}