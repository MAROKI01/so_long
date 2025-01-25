#include "../include/so_long_utils.h"

void load_textures(t_data *data)
{
    data->img_size = IMG_SIZE;  
    
    data->front_wall = new_file_img("textures/front wallv2.xpm", *data);
    data->middle_wall = new_file_img("textures/middle wall.xpm", *data);
    data->floor = new_file_img("textures/floor.xpm",*data);
    data->collect = new_file_img("textures/coin.xpm",*data);
    data->exit = new_file_img("textures/exit.xpm",*data);
    data->exit_open = new_file_img("textures/exit_open.xpm",*data);
    data->player = new_file_img("textures/char.xpm",*data);

}