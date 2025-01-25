#include "../include/so_long_utils.h"

static int count_map_lines(char *filename)
{
    int fd = open(filename, O_RDONLY);
    int height = 0;
    char *line;

    if (fd < 0)
        return (-1);
    
    while ((line = get_next_line(fd)))
    {
        height++;
        free(line);
    }
    close(fd);
    return (height);
}

static int validate_map_dimensions(t_data *data, char *line, int index)
{
    if (index == 0)
    {
        data->width = ft_strlen(line) - 1;
        return (1);
    }
    return (!check_line_length(line, data->width));
}

static char **allocate_grid(int height)
{
    char **grid = malloc(sizeof(char *) * (height + 1));
    if (!grid)
        return (NULL);
    return (grid);
}

static int populate_grid(t_data *data, char *filename)
{
    int fd = open(filename, O_RDONLY);
    int i = 0;
    char *line;

    if (fd < 0)
        return (0);

    while ((line = get_next_line(fd)) && i < data->height)
    {
        if (!validate_map_dimensions(data, line, i))
        {
            close(fd);
            printf("Error: Map is not rectangular");
            return (0);
        }
        data->grid[i++] = line;
    }
    data->grid[i] = NULL;
    close(fd);
    return (1);
}

int read_map(t_data *data, char *filename)
{
    data->height = count_map_lines(filename);
    if (data->height <= 0)
        return (0);

    data->grid = allocate_grid(data->height);
    if (!data->grid)
        return (0);

    return (populate_grid(data, filename));
}
