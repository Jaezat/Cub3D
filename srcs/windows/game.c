#include "main.h"

void	get_addr(t_umlx *u)
{
	t_img_data	*im;

	im = &u->img_data;
	im->addr = (int *)mlx_get_data_addr(u->img, &im->bpp, &im->line_s,
			&im->endian);
}

void	paint_put(t_umlx *u)
{
	int	i;

	i = 0;
	while (i < WIN_H * WIN_W)
	{
		u->img_data.addr[i] = rand();
		i++;
	}
	mlx_put_image_to_window(u->mlx, u->win, u->img, 0, 0);
}

void	game(t_data *d)
{
	t_game env;

	ft_bzero(&env, sizeof(t_game));
	env.u.d = d;
	env.mn.d = d;
	env.u.mlx = mlx_init();
	if (!env.u.mlx)
		exit_exec(&env.u, 1);
	env.u.win = mlx_new_window(env.u.mlx, WIN_W, WIN_H, "Cenv.ub3d");
	if (!env.u.win)
		exit_exec(&env.u, 1);
	env.u.img = mlx_new_image(env.u.mlx, WIN_W, WIN_H);
	get_addr(&env.u);
	env.mn.ulx = env.u;
	// load_textenv.ures(&env.u);
	mlx_key_hook(env.u.win, hook, &env.u);
	mlx_loop_hook(env.u.mlx, (int (*)())(void *)loop, &env);
	mlx_loop(env.u.mlx);
}

// void	game(t_data *d)
// {
// 	t_umlx	u;

// 	ft_bzero(&u, sizeof(t_umlx));
// 	u.d = d;
// 	u.mlx = mlx_init();
// 	if (!u.mlx)
// 		exit_exec(&u, 1);
// 	u.win = mlx_new_window(u.mlx, WIN_W, WIN_H, "Cub3d");
// 	if (!u.win)
// 		exit_exec(&u, 1);
// 	load_textures(&u);
// 	// u.img = mlx_new_image(u.mlx, WIN_W, WIN_H);
// 	mlx_key_hook(u.win, hook, &u);
// 	mlx_loop_hook(u.mlx, (int (*)())(void *)loop, &u);
// 	mlx_loop(u.mlx);
// }
