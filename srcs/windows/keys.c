#include "main.h"

void	press_key(int keycode, t_game *env) // in case we are not using library X11 then change keys variables
{
	if (keycode == XK_Escape)
		exit_exec(&env->u, 0);
	if (keycode == XK_Left)
		env->u.d->key.left = 1;
	if (keycode == XK_Right)
		env->u.d->key.right = 1;
	if (keycode == XK_W || keycode == XK_w)
		env->u.d->key.w = 1;
	if (keycode == XK_A || keycode == XK_a)
		env->u.d->key.a = 1;
	if (keycode == XK_S || keycode == XK_s)
		env->u.d->key.s = 1;
	if (keycode == XK_D || keycode == XK_d)
		env->u.d->key.d = 1;
}

void release_key(int keycode, t_game *env)
{
	if (keycode == XK_Escape)
		exit_exec(&env->u, 0);
	if (keycode == XK_Left)
		env->u.d->key.left = 0;
	if (keycode == XK_Right)
		env->u.d->key.right = 0;
	if (keycode == XK_W || keycode == XK_w)
		env->u.d->key.w = 0;
	if (keycode == XK_A || keycode == XK_a)
		env->u.d->key.a = 0;
	if (keycode == XK_S || keycode == XK_s)
		env->u.d->key.s = 0;
	if (keycode == XK_D || keycode == XK_d)
		env->u.d->key.d = 0;
}

void close_windows(t_game *env) // should i just pass exit_exec?
{
	exit_exec(&env->u, 0);
}

void hooks_keys(t_game *env)
{
	mlx_hook(env->u.win, KeyPress, KeyPressMask, press_key, env);
	mlx_hook(env->u.win, KeyRelease, KeyReleaseMask, release_key, env);
	mlx_hook(env->u.win, DestroyNotify, NoEventMask, close_windows, env);
}


/* void	key_press(int keycode, void *param)
{
	t_game	*env;
	t_data	*data;
	t_umlx	*umlx;

	env = param;
	data = env->u.d;
	umlx = &env->u;
	(void)umlx;
	if (keycode == K_W)
		data->py -= MOV_INC;
	if (keycode == K_S)
		data->py += MOV_INC;
	if (keycode == K_A)
		data->px -= MOV_INC;
	if (keycode == K_D)
		data->px += MOV_INC;
	if (keycode == K_RIGHT)
		data->dir -= ANG_INC * M_PI / 180.0;
	if (keycode == K_LEFT)
		data->dir += ANG_INC * M_PI / 180.0;
} */
