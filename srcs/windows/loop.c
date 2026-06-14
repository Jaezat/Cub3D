#include "main.h"

// void movement(t_env *env)
// {
// 	float dir;

// 	dir = env->data.dir;
// 	// W: Para delante
// 	if (env->data->keys.w == 1)
// 	{
// 		env->data->px += cos(dir) * MOV_INC;
// 		env->data->py += sin(dir) * MOV_INC;
// 	}
// 	else if (env->data->keys.s == 1)
// 	{
// 		env->data->px -= cos(dir) * MOV_INC;
// 		env->data->py -= sin(dir) * MOV_INC;
// 	}
	
// }

// void rotation(t_env *env)
// {
// 	if (env->data->keyss.right == 1)
// 		env->data.dir += ANG_INC * RAD;
// 	if (env->data->keys.left == 1)
// 		env->data.dir -= ANG_INC * RAD;
// }

void	movement(t_env *game)
{
	t_data	*data;
	float	x;
	float	y;

	data = game->data;
	x = data->px;
	y = data->py;
	if (game->keys.left)
		data->dir -= ANG_INC * M_PI / 180.0;
	if (game->keys.right)
		data->dir += ANG_INC * M_PI / 180.0;
	if (game->keys.w)
	{
		data->py += sin(data->dir) * MOV_INC;
		data->px += cos(data->dir) * MOV_INC;
	}
	if (game->keys.s)
	{
		data->py -= sin(data->dir) * MOV_INC;
		data->px -= cos(data->dir) * MOV_INC;
	}
	if (game->keys.a)
	{
		data->py -= (sin(data->dir) + 1.57079633 * MOV_INC);
		data->px -= (cos(data->dir) + 1.57079633 * MOV_INC);
	}
	if (game->keys.d)
	{
		data->py += (sin(data->dir) + 1.57079633 * MOV_INC);
		data->px += (cos(data->dir) + 1.57079633 * MOV_INC);
	}

}

int	loop(void *param)
{
	t_env	*env;

	env = (t_env *)param;
	
	movement(env);
	draw_minimap(env);
	mlx_put_image_to_window(env->umlx.mlx, env->umlx.win, env->umlx.img, 0, 0);
	usleep(1000000 / 60);
	return (0);
}