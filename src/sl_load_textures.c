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
    data->zero = new_file_img("textures/digits/0.xpm",*data);
    data->one = new_file_img("textures/digits/1.xpm",*data);
    data->two = new_file_img("textures/digits/2.xpm",*data);
    data->three = new_file_img("textures/digits/3.xpm",*data);
    data->four = new_file_img("textures/digits/4.xpm",*data);
    data->five = new_file_img("textures/digits/5.xpm",*data);
    data->six = new_file_img("textures/digits/6.xpm",*data);
    data->seven = new_file_img("textures/digits/7.xpm",*data);
    data->eight = new_file_img("textures/digits/8.xpm",*data);
    data->nine = new_file_img("textures/digits/9.xpm",*data);
    data->move_n = new_file_img("textures/digits/move_n.xpm",*data);

}