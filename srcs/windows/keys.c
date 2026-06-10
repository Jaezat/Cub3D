#include "main.h"

/* 
before claude

void	press_key(int keycode, t_env *env) // in case we are not using library X11 then change keys variables
{
	if (keycode == XK_Escape)
		exit_exec(&env->umlx, 0);
	if (keycode == XK_Left)
		env->umlx.d->key.left = 1;
	if (keycode == XK_Right)
		env->umlx.d->key.right = 1;
	if (keycode == XK_W || keycode == XK_w)
		env->umlx.d->key.w = 1;
	if (keycode == XK_A || keycode == XK_a)
		env->umlx.d->key.a = 1;
	if (keycode == XK_S || keycode == XK_s)
		env->umlx.d->key.s = 1;
	if (keycode == XK_D || keycode == XK_d)
		env->umlx.d->key.d = 1;
}

void release_key(int keycode, t_env *env)
{
	if (keycode == XK_Escape)
		exit_exec(&env->u, 0);
	if (keycode == XK_Left)
		env->umlx.d->key.left = 0;
	if (keycode == XK_Right)
		env->umlx.d->key.right = 0;
	if (keycode == XK_W || keycode == XK_w)
		env->umlx.d->key.w = 0;
	if (keycode == XK_A || keycode == XK_a)
		env->umlx.d->key.a = 0;
	if (keycode == XK_S || keycode == XK_s)
		env->umlx.d->key.s = 0;
	if (keycode == XK_D || keycode == XK_d)
		env->umlx.d->key.d = 0;
}

void close_windows(t_env *env) // should i just pass exit_exec?
{
	exit_exec(&env->u, 0);
}

void hooks_keys(t_env *env)
{
	mlx_hook(env->umlx.win, KeyPress, KeyPressMask, press_key, env);
	mlx_hook(env->umlx.win, KeyRelease, KeyReleaseMask, release_key, env);
	mlx_hook(env->umlx.win, DestroyNotify, NoEventMask, close_windows, env);
}

 */

 #include "main.h"

void	press_key(int keycode, t_env *env)
{
	if (keycode == XK_Escape)
		exit_exec(&env->umlx, 0);
	if (keycode == XK_Left)
		env->data->key.left = 1;
	if (keycode == XK_Right)
		env->data->key.right = 1;
	if (keycode == XK_W || keycode == XK_w)
		env->data->key.w = 1;
	if (keycode == XK_A || keycode == XK_a)
		env->data->key.a = 1;
	if (keycode == XK_S || keycode == XK_s)
		env->data->key.s = 1;
	if (keycode == XK_D || keycode == XK_d)
		env->data->key.d = 1;
}

void	release_key(int keycode, t_env *env)
{
	if (keycode == XK_Escape)
		exit_exec(&env->umlx, 0);
	if (keycode == XK_Left)
		env->data->key.left = 0;
	if (keycode == XK_Right)
		env->data->key.right = 0;
	if (keycode == XK_W || keycode == XK_w)
		env->data->key.w = 0;
	if (keycode == XK_A || keycode == XK_a)
		env->data->key.a = 0;
	if (keycode == XK_S || keycode == XK_s)
		env->data->key.s = 0;
	if (keycode == XK_D || keycode == XK_d)
		env->data->key.d = 0;
}

void	close_windows(t_env *env)
{
	exit_exec(&env->umlx, 0);
}

void	hooks_keys(t_env *env)
{
	mlx_hook(env->umlx.win, KeyPress, KeyPressMask, press_key, env);
	mlx_hook(env->umlx.win, KeyRelease, KeyReleaseMask, release_key, env);
	mlx_hook(env->umlx.win, DestroyNotify, NoEventMask, close_windows, env);
}