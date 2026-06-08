#include "main.h"

void	key_press(int keycode, void *param)
{
	t_game	*env;
	t_data	*d;
	t_umlx	*umlx;

	env = param;
	d = env->u.d;
	umlx = &env->u;
	if (keycode == K_W)
		env->key.w = true;
	if (keycode == K_S)
		env->key.s = true;
	if (keycode == K_A)
		env->key.a = true;
	if (keycode == K_D)
		env->key.d = true;
	if (keycode == K_RIGHT)
		env->key.right = true;
	if (keycode == K_LEFT)
		env->key.left = true;
	if (keycode == K_ESC)
		exit_exec(umlx, 0);
}

void	key_release(int keycode, void *param)
{
	t_game	*env;
	t_data	*d;
	t_umlx	*umlx;

	env = param;
	d = env->u.d;
	umlx = &env->u;
	if (keycode == K_W)
		env->key.w = false;
	if (keycode == K_S)
		env->key.s = false;
	if (keycode == K_A)
		env->key.a = false;
	if (keycode == K_D)
		env->key.d = false;
	if (keycode == K_RIGHT)
		env->key.right = false;
	if (keycode == K_LEFT)
		env->key.left = false;
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

void	movement(t_game *game)
{
	t_data	*data;
	float	x;
	float	y;

	data = game->u.d;
	x = data->px;
	y = data->py;
	if (game->key.left)
		data->dir -= ANG_INC * M_PI / 180.0;
	if (game->key.right)
		data->dir += ANG_INC * M_PI / 180.0;
	if (game->key.w)
	{
		data->py += sin(data->dir) * MOV_INC;
		data->px += cos(data->dir) * MOV_INC;
	}
	if (game->key.s)
	{
		data->py -= sin(data->dir) * MOV_INC;
		data->px -= cos(data->dir) * MOV_INC;
	}
	if (game->key.a)
	{
		data->py -= sin(data->dir + (90 * M_PI / 180)) * MOV_INC;
		data->px -= cos(data->dir + (90 * M_PI / 180)) * MOV_INC;
	}
	if (game->key.d)
	{
		data->py += sin(data->dir + (90 * M_PI / 180)) * MOV_INC;
		data->px += cos(data->dir + (90 * M_PI / 180)) * MOV_INC;
	}
	if (data->map[(int)data->py][(int)data->px] == '1')
	{
		data->px = data->map_w / 2;
		data->py = data->map_h / 2;
	}
}

int	loop(void *param)
{
	t_game	*env;

	env = (t_game *)param;
	movement(env);
	put_background(&env->u);
	mlx_put_image_to_window(env->u.mlx, env->u.win, env->u.img, 0, 0);
	usleep(1000000 / 60);
	return (0);
}
