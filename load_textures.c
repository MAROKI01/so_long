#include "so_long_utils.h"

void load_textures(t_data *data)
{
    data->img_size = IMG_SIZE;  
    
    // Load textures - replace paths with your actual texture paths
    data->wall = new_file_img("textures/wall.xpm", *data);
    data->floor = new_file_img("textures/floor.xpm",*data);
    data->collect = new_file_img("textures/coin.xpm",*data);
    data->exit = new_file_img("textures/exit.xpm",*data);
    data->player = new_file_img("textures/player32.xpm",*data);
}