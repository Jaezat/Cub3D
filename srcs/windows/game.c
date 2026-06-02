#include "main.h"

// this can be removed on 42's pcs maybe
static inline t_clean	func(void *func)
{
	return ((t_clean)func);
}

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
	mlx_key_hook(env.u.win, hook, &env);
	mlx_hook(env.u.win, 2, 1, func(key_press), &env);
	mlx_loop_hook(env.u.mlx, func(loop), &env);
	mlx_loop(env.u.mlx);
}
