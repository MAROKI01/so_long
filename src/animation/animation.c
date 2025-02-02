# include "../../include/so_long_utils.h"
#include <unistd.h>

int animation(t_data *data)
{
	int i;

	i = 0;

	while (i < 11 && data->objects.player.frames[i].ptr)
	{
		render_map(data);
		render_player(data, &data->objects.player.frames[i], data->player.p_x, data->player.p_y);
		usleep(10000);
		// ft_printf("test %d", i);
		i++;
	}
	return(0);
}