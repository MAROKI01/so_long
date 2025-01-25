#include "../include/so_long_utils.h"

//function to get pixel
unsigned int get_pixel_img(t_img src, int x, int y)
{
	return(*(unsigned int *)(src.addr + (y * src.line_length) + (x * src.bpp / 8)));
}
//function to put pixel
void put_pixel_img(t_img *dest, int pixel, int x, int y)
{
	if (pixel == (int)0xFF000000)
		return ;
	*(unsigned int *)(dest->addr + (y * dest->line_length) + (x * dest->bpp / 8)) = pixel;
}
//function to put img to img
void put_img_to_img(t_img *dest, t_img *src, int x, int y)
{
	int i;
	int j;

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
// create new image
t_img	new_file_img(char *path, t_data data)
{
	t_img	new_img;

	new_img.ptr = mlx_xpm_file_to_image(data.mlx, path, &(new_img.w), &(new_img.h));
	if (!new_img.ptr)
		write(2, "File could not be read\n", 23);
	else
		new_img.addr = mlx_get_data_addr(new_img.ptr, &(new_img.bpp),&(new_img.line_length),&(new_img.endian));
	return(new_img);
}