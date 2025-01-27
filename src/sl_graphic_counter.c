#include "../include/so_long_utils.h"

void render_digits(t_data *data, char str, int step)
{
	if (str == '0')
			render_player(data, &data->zero, step,3);
		if (str == '1')
			render_player(data, &data->one, step,3);
		if (str == '2')
			render_player(data, &data->two, step,3);
		if (str == '3')
			render_player(data, &data->three, step,3);
		if (str == '4')
			render_player(data, &data->four, step,3);
		if (str == '5')
			render_player(data, &data->five, step,3);
		if (str == '6')
			render_player(data, &data->six, step,3);
		if (str == '7')
			render_player(data, &data->seven, step,3);
		if (str == '8')
			render_player(data, &data->eight, step,3);
		if (str == '9')
			render_player(data, &data->nine, step,3);
}

void graphic_counter(t_data *data)
{
	char *counter;
	int i;
	int step;

	i = 0;
	step = 162;
	counter = ft_itoa(data->moves_counter);
	render_player(data, &data->move_n, 32,3);
	while (counter[i])
	{
		render_digits(data, counter[i],step);
		i++;
		step+=21;
	}
}
