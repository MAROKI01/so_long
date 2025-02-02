# include "../../include/so_long_utils.h"

void load_frames(t_data *data)
{
	if (!data)
	return;
	data->objects.player.frames = NULL;
	data->objects.player.frames = malloc(sizeof(t_img) * 11);
	if (!data->objects.player.frames)
		return;
	
	data->objects.player.frames[0] = new_file_img("textures/sprites/wld1/1.xpm", *data);
	data->objects.player.frames[1] = new_file_img("textures/sprites/wld1/2.xpm", *data);
	data->objects.player.frames[2] = new_file_img("textures/sprites/wld1/3.xpm", *data);
	data->objects.player.frames[3] = new_file_img("textures/sprites/wld1/4.xpm", *data);
	data->objects.player.frames[4] = new_file_img("textures/sprites/wld1/5.xpm", *data);
	data->objects.player.frames[5] = new_file_img("textures/sprites/wld1/6.xpm", *data);
	data->objects.player.frames[6] = new_file_img("textures/sprites/wld1/7.xpm", *data);
	data->objects.player.frames[7] = new_file_img("textures/sprites/wld1/8.xpm", *data);
	data->objects.player.frames[8] = new_file_img("textures/sprites/wld1/9.xpm", *data);
	data->objects.player.frames[9] = new_file_img("textures/sprites/wld1/10.xpm", *data);
	data->objects.player.frames[10] = new_file_img("textures/sprites/wld1/11.xpm", *data);
	
}