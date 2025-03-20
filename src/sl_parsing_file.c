#include "../include/so_long_utils.h"

int	check_file(char *file)
{
	int is_file_valid;

	is_file_valid = 0;
	if (ft_strnstr(file, ".ber", ft_strlen(file)))
		is_file_valid = 1;
	return (is_file_valid);
	return (0);
}