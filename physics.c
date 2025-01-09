#include "so_long_utils.h"

int gravity(t_data *data)
{
	if (data->image.p_y < 650)
	{
		data->image.p_y += 1;
		
	}
	return(0);
}