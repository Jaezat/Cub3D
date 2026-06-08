#include "main.h"

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

void					key_release(int keycode, void *param);

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
	// gm.mn.ulx = gm.u;
	// player_set_discreet(&gm);
	// mlx_key_hook(gm.umlx.win, hook, &gm);
	// mlx_hook(gm.umlx.win, 2, 1 << 0, func(key_press), &gm);
	// mlx_hook(gm.umlx.win, 3, 1 << 1, func(key_release), &gm);
	mlx_loop_hook(gm.umlx.mlx, func(loop), &gm);
	mlx_loop(gm.umlx.mlx);
}
