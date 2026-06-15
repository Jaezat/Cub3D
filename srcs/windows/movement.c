#include "main.h"

static void rotation(t_env *game)
{
	if (game->keys.left)
		game->data->dir -= ANG_INC * M_PI / 180.0;
	if (game->keys.right)
		game->data->dir += ANG_INC * M_PI / 180.0;
}

static bool check_margin(t_data *data, float new_y, float new_x)
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

static void checking_position(t_data *data, float new_y, float new_x)
{
	if (check_margin(data, new_y, new_x + MARGIN)
		&& check_margin(data, new_y, new_x - MARGIN))
		data->px = new_x;
	if (check_margin(data, new_y + MARGIN, new_x)
		&& check_margin(data, new_y - MARGIN, new_x))
		data->py = new_y;
}

static void direction(t_env *game)
{
	t_data	*data;
	float new_x;
	float new_y;

	data = game->data;
	new_y = data->py;
	new_x = data->px;
	if (game->keys.w)
	{
		new_y += sin(data->dir) * MOV_INC;
		new_x += cos(data->dir) * MOV_INC;
	}
	if (game->keys.s)
	{
		new_y -= sin(data->dir) * MOV_INC;
		new_x -= cos(data->dir) * MOV_INC;
	}
	if (game->keys.a)
	{
		new_y -= sin(data->dir + ANG) * MOV_INC;
		new_x -= cos(data->dir + ANG) * MOV_INC;
	}
	if (game->keys.d)
	{
		new_y += sin(data->dir + ANG) * MOV_INC;
		new_x += cos(data->dir + ANG) * MOV_INC;
	}
	checking_position(data, new_y, new_x);
}

void	movement(t_env *game)
{
	rotation(game);
	direction(game);
}