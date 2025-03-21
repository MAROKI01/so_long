/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_keys_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 00:25:36 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/21 10:03:54 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_utils.h"

static int	is_colliding_with_object(t_data *data, char object, int new_x,
		int new_y)
{
	t_collision_box	box;
	int				x;
	int				y;

	box.offset_left = 0;
	box.offset_right = 77;
	box.offset_top = 0;
	box.offset_bottom = 90;
	box.col_x = new_x + box.offset_left;
	box.col_y = new_y + box.offset_top;
	box.col_w = PLAYER_W - (box.offset_left + box.offset_right);
	box.sample_step = 4;
	y = box.col_y;
	while (y < box.col_y + PLAYER_H - (box.offset_top + box.offset_bottom))
	{
		x = box.col_x;
		while (x < box.col_x + box.col_w)
		{
			if (check_cell(data, object, x, y))
				return (1);
			x += box.sample_step;
		}
		y += box.sample_step;
	}
	return (0);
}

static int	check_precise_collision(t_data *data)
{
	int	new_y;
	int	new_x;

	new_y = data->player.p_y;
	new_x = data->player.p_x;
	if (data->keys[XK_w])
		new_y -= PLAYER_STEP;
	if (data->keys[XK_d])
		new_x += PLAYER_STEP;
	if (data->keys[XK_s])
		new_y += PLAYER_STEP;
	if (data->keys[XK_a])
		new_x -= PLAYER_STEP;
	if (is_colliding_with_object(data, '1', new_x, new_y))
		return (0);
	handle_coin_collection(data, new_x, new_y);
	if ((is_colliding_with_object(data, 'E', new_x, new_y)
			&& data->is_exit_open))
	{
		ft_printf("You won! Moves: %d\n", data->moves_counter);
		clean_up(data);
		exit(0);
	}
	return (-1);
}

static void	update_idle_state(t_data *data)
{
	if (!data->keys[XK_w] && !data->keys[XK_d]
		&& !data->keys[XK_s] && !data->keys[XK_a])
	{
		data->player.direction = IDLE;
		data->current_sprite = data->sprites.idle;
	}
}

static void	update_moves_counter(t_data *data, int check)
{
	if ((data->keys[XK_w] || data->keys[XK_d]
			|| data->keys[XK_s] || data->keys[XK_a])
		&& check != 0)
	{
		data->moves_counter++;
		ft_printf("Move number %d\n", data->moves_counter);
	}
}

int	keys_function(void *param)
{
	t_data		*data;
	int			check;
	static int	move_delay = 0;

	data = (t_data *)param;
	check = check_precise_collision(data);
	if (++move_delay < 10000)
		return (0);
	move_delay = 0;
	update_movement_keys(data, check);
	update_idle_state(data);
	update_moves_counter(data, check);
	return (0);
}
