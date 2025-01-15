#include "so_long_utils.h"
void    render_tile(t_data *data, t_img *tile, int x, int y)
{
	if (data && tile)
   		put_img_to_img(&data->background, tile, 
        x * data->img_size, y * data->img_size);
}

void    render_player(t_data *data, t_img *tile, int x, int y)
{
	if (data && tile)
   		put_img_to_img(&data->background, tile, 
        x , y );
}

int    render_map(t_data *data)
{
    int x;
    int y;

	if (!data)
		return(1);
    // Create new background image for each render
    if (data->background.ptr)
        mlx_destroy_image(data->mlx, data->background.ptr);
    
    // Create new background image with data dimensions
    data->background.ptr = mlx_new_image(data->mlx, 
        data->width * data->img_size, 
        data->height * data->img_size);
    data->background.addr = mlx_get_data_addr(data->background.ptr,
        &data->background.bpp,
        &data->background.line_length,
        &data->background.endian);

    // Render data to background image
    y = 0;
    while (y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
			if (data->grid[y][x] == '\n')
				break;
            // Draw floor everywhere first
			if (data->grid[y][x] != '1')
            	render_tile(data, &data->floor, x, y);
            
            // Draw other elements on top
            if (data->grid[y][x] == '1')
			{
				if (y >= 1 && data->grid[y - 1][x] != '1')
					render_tile(data, &data->front_wall, x, y);
				else
					render_tile(data, &data->middle_wall, x, y);
			}
            else if (data->grid[y][x] == 'C')
                render_tile(data, &data->collect, x, y);
            else if (data->grid[y][x] == 'E')
                render_tile(data, &data->exit, x, y);
            else
				render_player(data, &data->player, data->player.p_x, data->player.p_y);
            x++;
        }
        y++;
    }
    
    // Put the complete background to window
    mlx_put_image_to_window(data->mlx, data->win, data->background.ptr, 0, 0);
	return(0);
}