#include "../include/so_long_utils.h"

int check_line_length(char *line, int width)
{
    int len;

    if (!line)
        return (0);
    len = ft_strlen(line);
    if (line[len - 1] == '\n')
	{
        len--;
	}
    return (len != width);
}