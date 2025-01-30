#include "../include/so_long_utils.h"

int init_game(char *data_file)
{
    t_data   data;
    // Initialize everything to 0
    ft_memset(&data, 0, sizeof(t_data));

    data.mlx = mlx_init();
    if (!data.mlx)
        return (0);

    if (!read_map(&data, data_file))
    {
        clean_up(&data);
        return (0);
    }
	
	init_player_pos(&data);

	if (!map_checker(&data))
		return(1);
    // Create window based on data size
    data.win = mlx_new_window(data.mlx, 
        data.width * IMG_SIZE, data.height * IMG_SIZE, "So long");
    if (!data.win)
    {
        clean_up(&data);
        return (0);
    }
	// In your initialization function

    // Load textures
    load_textures(&data);

	// Initialize the player position
	init_player_pos(&data);

    // Initial render
    render_map(&data);

    // Set up hooks
   	manage_hooks(&data);
    return (1);
}

int main(int ac, char **av)
{
	(void)ac;
	init_game(av[1]);
	return (0);
}