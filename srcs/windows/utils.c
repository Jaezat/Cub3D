#include "main.h"

bool check_margin(t_data *data, float new_y, float new_x)
{
	char **map;

	map = data->map;
	if (new_y < 0 || new_y >= MAP_H)
		return (false);
	if (new_x < 0 || new_x >= MAP_W)
		return (false);	
	if (map[(int)new_y][(int)new_x] == '1')
		return (false);
	return (true);
}

void checking_position(t_data *data, float new_y, float new_x)
{
	if (check_margin(data, new_y, new_x + MARGIN)
		&& check_margin(data, new_y, new_x - MARGIN))
		data->px = new_x;
	if (check_margin(data, new_y + MARGIN, new_x)
		&& check_margin(data, new_y - MARGIN, new_x))
		data->py = new_y;
}

