#include "main.h"

static void rotation(t_env *game)
{
    float old_x; 
    float old_y; 
    float c;
    float s;

	old_x = game->data->dir_x;
	old_y = game->data->dir_y;
	c = cos(ANG_V);
	s = sin(ANG_V);
	if (game->keys.left)
    {
        game->data->dir_x = old_x * c + old_y * s;
        game->data->dir_y = -old_x * s + old_y * c; 
    }
    if (game->keys.right)
    {
        game->data->dir_x = old_x * c - old_y * s;
        game->data->dir_y = old_x * s + old_y * c;
    }
}

static void moving_keys(t_env *game, float *new_x, float *new_y)
{
    if (game->keys.w)
    {
        *new_x += game->data->dir_x * MOV_INC;
        *new_y += game->data->dir_y * MOV_INC;
    }
    if (game->keys.s)
    {
        *new_x -= game->data->dir_x * MOV_INC;
        *new_y -= game->data->dir_y * MOV_INC;
    }
    if (game->keys.a) 
    {
        *new_x += game->data->dir_y * MOV_INC; 
        *new_y -= game->data->dir_x * MOV_INC; 
    }
    if (game->keys.d)
    {
        *new_x -= game->data->dir_y * MOV_INC; 
        *new_y += game->data->dir_x * MOV_INC; 
    }
}

static void direction(t_env *game)
{
	float new_x;
	float new_y;

	new_y = game->data->py;
	new_x = game->data->px;
	moving_keys(game, &new_x, &new_y);
	checking_position(game->data, &new_y, &new_x);
}

void	movement(t_env *game)
{
	rotation(game);
	direction(game);
}