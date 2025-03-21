/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_img_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:59:54 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/21 01:11:31 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_utils.h"

unsigned int	get_pixel_img(t_img src, int x, int y)
{
	return (*(unsigned int *)(src.addr + (y * src.line_length) + (x * src.bpp
			/ 8)));
}

void	put_pixel_img(t_img *dest, int pixel, int x, int y)
{
	if (pixel == (int)0xFF000000 || pixel == (int)0x00000000)
		return ;
	*(unsigned int *)(dest->addr + (y * dest->line_length) + (x * dest->bpp
				/ 8)) = pixel;
}

void	put_img_to_img(t_img *dest, t_img *src, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < src->h)
	{
		j = 0;
		while (j < src->w)
		{
			put_pixel_img(dest, get_pixel_img(*src, j, i), x + j, y + i);
			j++;
		}
		i++;
	}
}

t_img	new_file_img(char *path, t_data data)
{
	t_img	new_img;

	new_img.ptr = mlx_xpm_file_to_image(data.mlx, path, &(new_img.w),
			&(new_img.h));
	if (!new_img.ptr)
	{
		write(2, "File could not be read\n", 23);
		clean_up(&data);
		exit(1);
	}
	else
		new_img.addr = mlx_get_data_addr(new_img.ptr, &(new_img.bpp),
				&(new_img.line_length), &(new_img.endian));
	return (new_img);
}
