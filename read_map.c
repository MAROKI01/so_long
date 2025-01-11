#include "so_long_utils.h"

int check_line_length(char *line, int width)
{
    int len;

    if (!line)
        return (0);
    len = ft_strlen(line);
    if (line[len - 1] != '\n')
        len++;
    return (len == width);
}
int read_map(t_data *data, char *filename)
{
    int     fd;
    int     i;
    char    *line;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (0);
		
    // Count number of lines
    data->height = 0;
    while ((line = get_next_line(fd)))
    {
        data->height++;
        free(line);  // Free the line after counting
    }
    close(fd);
    // Allocate memory for the grid
    data->grid = malloc(sizeof(char *) * (data->height + 1));
    if (!data->grid)
        return (0);

    // Read map into grid
    fd = open(filename, O_RDONLY);
    i = 0;
    while ((line = get_next_line(fd)) && i < data->height)
    {
        data->grid[i] = line;
        if (i == 0)
		{
			data->width = ft_strlen(data->grid[0]) - 1;
		}
        else if (check_line_length(line, data->width))
        {
            close(fd);
            return (0);  // Invalid map: lines have different lengths
        }
        i++;
    }
    data->grid[i] = NULL;  // Null terminate the array
    close(fd);
    
    return (1);
}
