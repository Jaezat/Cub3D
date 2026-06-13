#include "main.h"

int	press_key(int keycode, t_env *env)
{
	if (keycode == XK_Escape)
		exit_exec(env, 0);
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
	return (0);
}

int	release_key(int keycode, t_env *env)
{
	if (keycode == XK_Escape)
		exit_exec(env, 0);
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
	return (0);
}

int	close_windows(t_env *env)
{
	exit_exec(env, 0);
	return (0);

}

void	hooks_keys(t_env *env)
{
	mlx_hook(env->umlx.win, KeyPress, KeyPressMask, press_key, env);
	mlx_hook(env->umlx.win, KeyRelease, KeyReleaseMask, release_key, env);
	mlx_hook(env->umlx.win, DestroyNotify, NoEventMask, close_windows, env);
}
