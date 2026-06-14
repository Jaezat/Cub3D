#include "main.h"

void rotation(t_env *env)
{
	if (env->data->keys.right == 1)
		env->data.dir += ANG_INC * RAD;
	if (env->data->keys.left == 1)
		env->data.dir -= ANG_INC * RAD;
}

void movement(t_env *env)
{
	float dir;

	dir = env->data.dir;
	// W: Para delante
	if (env->data->keys.w == 1)
	{
		env->data->px += cos(dir) * MOV_INC;
		env->data->py += sin(dir) * MOV_INC;
	}
	else if (env->data->keys.s == 1)
	{
		env->data->px -= cos(dir) * MOV_INC;
		env->data->py -= sin(dir) * MOV_INC;
	}
	
	

}

int	loop(void *param)
{
	t_env	*env;

	env = (t_env *)param;
	rotation(env);
	movement(env);
	draw_minimap(env);
	mlx_put_image_to_window(env->umlx.mlx, env->umlx.win, env->umlx.img, 0, 0);
	usleep(1000000 / 60);
	return (0);
}