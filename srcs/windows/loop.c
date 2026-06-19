#include "main.h"

int	loop(void *param)
{
	t_env	*env;

	env = (t_env *)param;
	
	movement(env);
	put_background(env);
	draw_minimap(env);
	mlx_put_image_to_window(env->umlx.mlx, env->umlx.win, env->umlx.img, 0, 0);
	usleep(1000000 / 60);
	return (0);
}
