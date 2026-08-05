#include "main.h"

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
	if (!gm.umlx.img)
		exit_msg_exec(&gm, "Failed to load MLX image pointer\n");
	get_addr(&gm.umlx);
	if (!gm.umlx.img_data.addr)
		exit_msg_exec(&gm, "Failed to load data address\n");
	hooks_keys(&gm);
	load_textures(&gm);
	mlx_loop_hook(gm.umlx.mlx, func(loop), &gm);
	mlx_loop(gm.umlx.mlx);
	exit_exec(&gm, 0);
}
