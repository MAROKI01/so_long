/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:32:01 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/21 01:35:44 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

void	destroy_window_anim(t_win w)
{
	if (w.mlx_ptr && w.win_ptr)
		mlx_destroy_window(w.mlx_ptr, w.win_ptr);
	if (w.mlx_ptr)
		free(w.mlx_ptr);
}
