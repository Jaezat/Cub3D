#include "main.h"

void	key_press(int keycode, void *param)
{
	t_game	*env;
	t_data	*data;
	t_umlx	*umlx;

	env = param;
	data = env->u.d;
	umlx = &env->u;
	(void)umlx;
	if (keycode == K_W)
	{
		data->py += sin(env->u.d->dir) * MOV_INC;
		data->px += cos(env->u.d->dir) * MOV_INC;
	}
	if (keycode == K_S)
	{
		data->py -= sin(env->u.d->dir) * MOV_INC;
		data->px -= cos(env->u.d->dir) * MOV_INC;
	}
	if (keycode == K_A)
	{
		data->py -= sin(env->u.d->dir + (90 * M_PI / 180)) * MOV_INC;
		data->px -= cos(env->u.d->dir + (90 * M_PI / 180)) * MOV_INC;
	}
	if (keycode == K_D)
	{
		data->py += sin(env->u.d->dir + (90 * M_PI / 180)) * MOV_INC;
		data->px += cos(env->u.d->dir + (90 * M_PI / 180)) * MOV_INC;
	}
	if (keycode == K_RIGHT)
		data->dir += ANG_INC * M_PI / 180.0;
	if (keycode == K_LEFT)
		data->dir -= ANG_INC * M_PI / 180.0;
}

void	pick_action(int keycode, t_umlx *u)
{
	(void)u;
	if (keycode == K_LEFT)
		printf("keycode: K_LEFT\n");
}

int	hook(int keycode, void *param)
{
	t_umlx	*u;

	u = param;
	if (keycode == K_ESC)
		exit_exec(u, 0);
	return (1);
}

// draw_minimap(&env->mn);
// minimap
// sleep is badly done
int	loop(void *param)
{
	t_game	*env;

	env = (t_game *)param;
	put_background(&env->u);
	mlx_put_image_to_window(env->u.mlx, env->u.win, env->u.img, 0, 0);
	usleep(1000000 / 60);
	return (0);
}
