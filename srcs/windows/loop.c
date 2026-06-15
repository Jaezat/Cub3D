#include "main.h"

void	key_press(int keycode, void *param)
{
	t_env	*env;
	t_keys	*k;

	env = param;
	k = &env->keys;
	if (keycode == K_W)
		k->w = true;
	if (keycode == K_S)
		k->s = true;
	if (keycode == K_A)
		k->a = true;
	if (keycode == K_D)
		k->d = true;
	if (keycode == K_RIGHT)
		k->right = true;
	if (keycode == K_LEFT)
		k->left = true;
	if (keycode == K_ESC)
		exit_exec(env, 0);
}

void	key_release(int keycode, void *param)
{
	t_env	*env;
	t_keys	*k;

	env = param;
	k = &env->keys;
	if (keycode == K_W)
		k->w = false;
	if (keycode == K_S)
		k->s = false;
	if (keycode == K_A)
		k->a = false;
	if (keycode == K_D)
		k->d = false;
	if (keycode == K_RIGHT)
		k->right = false;
	if (keycode == K_LEFT)
		k->left = false;
	if (keycode == K_ESC)
		exit_exec(env, 0);
}

void	movement(t_env *game)
{
	t_data	*d;
	t_keys	*k;

	k = &game->keys;
	d = game->data;
	if (k->left)
		d->dir -= ANG_INC * M_PI / 180.0;
	if (k->right)
		d->dir += ANG_INC * M_PI / 180.0;
	if (k->w)
	{
		d->py += sin(d->dir) * MOV_INC;
		d->px += cos(d->dir) * MOV_INC;
	}
	if (k->s)
	{
		d->py -= sin(d->dir) * MOV_INC;
		d->px -= cos(d->dir) * MOV_INC;
	}
	if (k->a)
	{
		d->py -= sin(d->dir + (90 * M_PI / 180)) * MOV_INC;
		d->px -= cos(d->dir + (90 * M_PI / 180)) * MOV_INC;
	}
	if (k->d)
	{
		d->py += sin(d->dir + (90 * M_PI / 180)) * MOV_INC;
		d->px += cos(d->dir + (90 * M_PI / 180)) * MOV_INC;
	}
	if (d->map[(int)d->py][(int)d->px] == '1')
	{
		d->px = d->map_w / 2;
		d->py = d->map_h / 2;
	}
}

int	loop(void *param)
{
	t_env	*env;

	env = (t_env *)param;
	movement(env);
	// put_background(env);
	mlx_put_image_to_window(env->umlx.mlx, env->umlx.win, env->umlx.img, 0, 0);
	usleep(1000000 / 60);
	return (0);
}
