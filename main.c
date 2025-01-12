#include "so_long_utils.h"

void init_player_pos(t_data *data)
{
	int x;
	int y;

	y = 0;
	 while (y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
			if (data->grid[y][x] == 'P')
			{
				data->player.p_x = x * IMG_SIZE;
				data->player.p_y = y * IMG_SIZE;
				return ;
			}
			x++;
		}
		y++;
	}
}

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

    // Create window based on data size
    data.win = mlx_new_window(data.mlx, 
        data.width * IMG_SIZE, data.height * IMG_SIZE, "Game");
    if (!data.win)
    {
        clean_up(&data);
        return (0);
    }

    // // Load textures
    load_textures(&data);

	// Initialize the player position
	init_player_pos(&data);

    // Initial render
    render_map(&data);

    // Set up hooks
   	manage_hooks(&data);
    return (1);
}

int main(void)
{
	init_game("map.ber");
	return (0);
}