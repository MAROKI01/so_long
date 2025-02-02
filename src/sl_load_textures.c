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
    data->player = new_file_img("textures/player.xpm",*data);
    data->digits.zero = new_file_img("textures/digits/0.xpm",*data);
    data->digits.one = new_file_img("textures/digits/1.xpm",*data);
    data->digits.two = new_file_img("textures/digits/2.xpm",*data);
    data->digits.three = new_file_img("textures/digits/3.xpm",*data);
    data->digits.four = new_file_img("textures/digits/4.xpm",*data);
    data->digits.five = new_file_img("textures/digits/5.xpm",*data);
    data->digits.six = new_file_img("textures/digits/6.xpm",*data);
    data->digits.seven = new_file_img("textures/digits/7.xpm",*data);
    data->digits.eight = new_file_img("textures/digits/8.xpm",*data);
    data->digits.nine = new_file_img("textures/digits/9.xpm",*data);
    data->digits.move_n = new_file_img("textures/digits/move_n.xpm",*data);
    data->enemy = new_file_img("textures/enemy.xpm",*data);

	load_frames(data);
}
