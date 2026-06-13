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
	// W: Para delante
	 

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