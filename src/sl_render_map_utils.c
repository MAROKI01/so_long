/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_render_map_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 00:39:06 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/21 00:39:17 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_utils.h"

void	render_tile(t_data *data, t_img *tile, int x, int y)
{
	if (data && tile)
		put_img_to_img(&data->background, tile, x * data->img_size, y
			* data->img_size);
}

void	render_player(t_data *data, t_img *tile, int x, int y)
{
	if (data && tile)
		put_img_to_img(&data->background, tile, x, y);
}
