#include "main.h"

/* OLD VERSION

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
	hooks_keys(&env);
	mlx_loop_hook(env.u.mlx, func(loop), &env);
	mlx_loop(env.u.mlx);
}
*/




// this can be removed on 42's pcs maybe
static inline t_clean	func(void *f_ptr)
{
	return ((t_clean)f_ptr);
}

// void	player_set_discreet(t_env *env)
// {
// 	t_data	*d;
// 	t_umlx	*u;

// 	d = env->u.d;
// 	u = &env->u;
// 	d->px = 1;
// 	d->py = 1;
// 	(void)u;
// }

/* 
before claude


void					key_release(int keycode, void *param);

// new version

void	game(t_data *d)
{
	t_env	gm;

	ft_bzero(&gm, sizeof(t_env));
	gm.data = d;
	gm.umlx.mlx = mlx_init();
	if (!gm.umlx.mlx)
		exit_exec(&gm, 1);
	gm.umlx.win = mlx_new_window(&gm.umlx, WIN_W, WIN_H, "Cub3D");
	if (!gm.umlx.win)
		exit_exec(&gm, 1);
	gm.umlx.img = mlx_new_image(gm.umlx.mlx, WIN_W, WIN_H);
	get_addr(&gm.umlx);
	gm.mn.ulx = gm.u;
	hooks_keys(&env);
	// player_set_discreet(&gm);
	mlx_loop_hook(gm.umlx.mlx, func(loop), &gm);
	mlx_loop(gm.umlx.mlx);
}
 */

/* static inline t_clean	func(void *f_ptr)
{
	return ((t_clean)f_ptr);
} */

void	game(t_data *d)
{
	t_env	gm;

	ft_bzero(&gm, sizeof(t_env));
	gm.data = d;
	gm.umlx.mlx = mlx_init();
	if (!gm.umlx.mlx)
		exit_exec(&gm, 1);
	gm.umlx.win = mlx_new_window(gm.umlx.mlx, WIN_W, WIN_H, "Cub3D");
	if (!gm.umlx.win)
		exit_exec(&gm, 1);
	gm.umlx.img = mlx_new_image(gm.umlx.mlx, WIN_W, WIN_H);
	// get_addr(&gm.umlx);
	hooks_keys(&gm);
	mlx_loop_hook(gm.umlx.mlx, func(loop), &gm);
	mlx_loop(gm.umlx.mlx);
}