# include "../../include/so_long_utils.h"
#include <unistd.h>


void state_animation(t_data *data, int state)
{
	int i;
	t_sprite sprite;

	i = 0;
	if (!data)
		return;
	if(state == idle)
		sprite = data->objects.player_idle;
	else if (state == wld1)
		sprite = data->objects.player_wld1;

	while (i < sprite.total_frames && sprite.frames[i].ptr)
	{
		render_player(data, &sprite.frames[i], data->player.p_x, data->player.p_y);
		render_map(data);
		usleep(40000);
		// ft_printf("test %d", i);
		i++;
	}
}

int animation(t_data *data)
{
	if (data->keys[XK_d])
		state_animation(data, wld1);
	else 
		state_animation(data, idle);
	return(0);
}