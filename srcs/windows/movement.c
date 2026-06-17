#include "main.h"

static void rotation(t_env *game)
{
	float old_x;
	float old_y;

	old_x = game->data->dir_x;
	old_y = game->data->dir_y;
	if (game->keys.left)
	{
		game->data->dir_x = old_x * cos(ANG_V) - old_y * sin(ANG_V);
		game->data->dir_y = old_x * sin(ANG_V) + old_y * cos(ANG_V)
	}
	if (game->keys.right)
	{

	}
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
		new_y += data->dir_y * MOV_INC;
		new_x += data->dir_x * MOV_INC;
	}
	if (game->keys.s)
	{
		new_y -= data->dir_y * MOV_INC;
		new_x -= data->dir_x * MOV_INC;
	}
	if (game->keys.a)
	{
		new_y -= data->dir_y * MOV_INC;
		new_x += data->dir_x * MOV_INC;
	}
	if (game->keys.d)
	{
		new_y += data->dir_y * MOV_INC;
		new_x -= data->dir_x * MOV_INC;
	}
	checking_position(data, new_y, new_x);
}

void	movement(t_env *game)
{
	rotation(game);
	direction(game);
}