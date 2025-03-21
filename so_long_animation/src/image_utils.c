/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntahadou <ntahadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:28:19 by ntahadou          #+#    #+#             */
/*   Updated: 2025/03/21 01:28:53 by ntahadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.h"

t_img	new_img_anim(int w, int h, t_win window)
{
	t_img	image;

	image.win = window;
	image.ptr = mlx_new_image(window.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.ptr, &(image.bpp),
			&(image.line_length), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}

void	put_pixel_img_anim(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xff000000)
		return ;
	if (x >= 0 && y >= 0 && x < img->w && y < img->h)
	{
		dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

t_img	new_file_img_anim(char *path, t_win window)
{
	t_img	image;

	image.win = window;
	image.ptr = mlx_xpm_file_to_image(window.mlx_ptr, path, &image.w, &image.h);
	if (!image.ptr)
		write(2, "File could not be read\n", 23);
	else
		image.addr = mlx_get_data_addr(image.ptr, &(image.bpp),
				&(image.line_length), &(image.endian));
	return (image);
}

unsigned int	get_pixel_img_anim(t_img img, int x, int y)
{
	return (*(unsigned int *)((img.addr + (y * img.line_length) + (x * img.bpp
				/ 8))));
}

void	destroy_image_anim(t_img img)
{
	if (img.ptr && img.win.mlx_ptr)
		mlx_destroy_image(img.win.mlx_ptr, img.ptr);
}
