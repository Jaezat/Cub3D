#include "main.h"

// this can be removed on 42's pcs maybe
static inline t_clean	func(void *f_ptr)
{
	return ((t_clean)f_ptr);
}

void	player_set_discreet(t_game *env)
{
	t_data	*d;
	t_umlx	*u;

	d = env->u.d;
	u = &env->u;
	d->px = 1;
	d->py = 1;
	(void)u;
}

void					key_release(int keycode, void *param);

void	game(t_data *d)
{
	t_game	env;

	ft_bzero(&env, sizeof(t_game));
	env.u.d = d;
	env.mn.d = d;
	env.u.mlx = mlx_init();
	if (!env.u.mlx)
		exit_exec(&env.u, 1);
	env.u.win = mlx_new_window(env.u.mlx, WIN_W, WIN_H, "Cub3D");
	if (!env.u.win)
		exit_exec(&env.u, 1);
	env.u.img = mlx_new_image(env.u.mlx, WIN_W, WIN_H);
	get_addr(&env.u);
	env.mn.ulx = env.u;
	// player_set_discreet(&env);
	mlx_key_hook(env.u.win, hook, &env);
	mlx_hook(env.u.win, 2, 1 << 0, func(key_press), &env);
	mlx_hook(env.u.win, 3, 1 << 1, func(key_release), &env);
	mlx_loop_hook(env.u.mlx, func(loop), &env);
	mlx_loop(env.u.mlx);
}
