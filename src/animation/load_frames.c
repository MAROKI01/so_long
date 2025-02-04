// # include "../../include/so_long_utils.h"

// void load_wld1(t_data *data)
// {
// 	int i;

// 	i = 0;
// 	data->objects.player_up.frames = NULL;
// 	data->objects.player_up.total_frames = 11;
// 	data->objects.player_up.frames = malloc(sizeof(t_img) * 11);
// 	if (!data->objects.player_up.frames)
// 		return;
// 	while (i < 11) {
//     char filename[256];
//     ft_sprintf(filename,"textures/sprites/wld1/%d.xpm",i + 1);
// 	printf("file name : %s\n", filename);
//     data->objects.player_up.frames[i] = new_file_img(filename, *data);
// 	i++;
// 	}
// }

// void load_idle(t_data *data)
// {
// 	int i;

// 	i = 0;
// 	data->objects.player_idle.frames = NULL;
// 	data->objects.player_idle.total_frames = 25;
// 	data->objects.player_idle.frames = malloc(sizeof(t_img) * 25);
// 	if (!data->objects.player_idle.frames)
// 		return;
// 	while (i < data->objects.player_idle.total_frames) {
//     char filename[256];
//     ft_sprintf(filename,"textures/sprites/idle/%d.xpm",i + 1);
// 	printf("file name : %s\n", filename);
//     data->objects.player_idle.frames[i] = new_file_img(filename, *data);
// 	i++;
// 	}
// }

// void load_up(t_data *data)
// {
// 	int i;

// 	i = 0;
// 	data->objects.player_up.frames = NULL;
// 	data->objects.player_up.total_frames = 11;
// 	data->objects.player_up.frames = malloc(sizeof(t_img) * 11);
// 	if (!data->objects.player_up.frames)
// 		return;
// 	while (i < data->objects.player_up.total_frames) {
//     char filename[256];
//     ft_sprintf(filename,"textures/sprites/up/%d.xpm",i + 1);
// 	printf("file name : %s\n", filename);
//     data->objects.player_up.frames[i] = new_file_img(filename, *data);
// 	i++;
// 	}
// }
// void load_frames(t_data *data)
// {
// 	if (!data)
// 	return;
	
// 	load_wld1(data);
// 	load_idle(data);
// 	load_up(data);
// }
