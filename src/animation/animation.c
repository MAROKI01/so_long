# include "../../include/so_long_utils.h"
#include <unistd.h>


void mov_anim(t_data *data, int move)
{
	int i;
	t_sprite sprite;

	i = 0;
	if (!data)
		return;
	if (move == up)
		sprite = data->objects.player_up;
	else if (move == right)
		sprite = data->objects.player_right;

	while (i < sprite.total_frames && sprite.frames[i].ptr)
	{
		render_player(data, &sprite.frames[i], data->player.p_x, data->player.p_y);
		render_map(data);
		usleep(40000);
		// ft_printf("test %d", i);
		i++;
	}
}

void idle_anim(t_data *data)
{
	int i;
	t_sprite sprite;

	i = 0;
	if (!data)
		return;
	sprite = data->objects.player_idle;
	while (i < sprite.total_frames && sprite.frames[i].ptr)
	{
		usleep(1500);
		render_player(data, &sprite.frames[i], data->player.p_x, data->player.p_y);
		// ft_printf("test %d", i);
		render_map(data);
		i++;
	}
}

int animation(t_data *data)
{
	if (data->keys[XK_d])
		mov_anim(data, right);
	// else if (data->keys[XK_w])
	// 	mov_anim(data, up);
	else 
		idle_anim(data);
	return(0);
}