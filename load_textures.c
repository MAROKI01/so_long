#include "so_long_utils.h"

void load_textures(t_data *data)
{
    data->img_size = IMG_SIZE;  
    
    // Load textures - replace paths with your actual texture paths
    data->front_wall = new_file_img("textures/custom assets/front wallv2.xpm", *data);
    data->back_wall = new_file_img("textures/custom assets/front wallv2.xpm", *data);
    data->right_wall = new_file_img("textures/custom assets/right wall.xpm", *data);
    data->left_wall = new_file_img("textures/custom assets/left wall.xpm", *data);
    data->corner_wall = new_file_img("textures/custom assets/corner wall.xpm", *data);
    data->middle_wall = new_file_img("textures/custom assets/middle wall.xpm", *data);
    data->floor = new_file_img("textures/custom assets/floor.xpm",*data);
    data->collect = new_file_img("textures/coin.xpm",*data);
    data->exit = new_file_img("textures/exit.xpm",*data);
    data->player = new_file_img("textures/custom assets/char.xpm",*data);

}