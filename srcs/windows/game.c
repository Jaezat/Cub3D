#include "main.h"



// this can be removed on 42's pcs maybe
static inline t_clean	func(void *f_ptr)
{
	return ((t_clean)f_ptr);
}

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
	get_addr(&gm.umlx);
	hooks_keys(&gm);
	mlx_loop_hook(gm.umlx.mlx, func(loop), &gm);
	mlx_loop(gm.umlx.mlx);
}
