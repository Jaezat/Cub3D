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
	int			j;
	int			i;
	int			r;
	int			g;
	int			b;
	int			newc;
	// static int	frame = 0;

	j = 0;
	while (j < WIN_W)
	{
		i = 0;
		while (i < WIN_H)
		{
			u->img_data.addr[WIN_W * i + j] = u->grad;
			i++;
		}
		j++;
		// printf("%x\n", newc);
	}
	newc = 0;
	r = (char)(u->grad >> (2 * 8));
	g = (char)(u->grad >> (1 * 8));
	b = (char)(u->grad >> (0 * 8));
	if ((0xffffff & rand()) % 6 == 0)
		r = (r + 1) % 256;
	if ((0xffffff & rand()) % 6 == 1)
		g = (g + 1) % 256;
	if ((0xffffff & rand()) % 6 == 2)
		b = (b + 1) % 256;
	if ((0xffffff & rand()) % 6 == 3)
		r = (r - 1) % 256;
	if ((0xffffff & rand()) % 6 == 4)
		g = (g - 1) % 256;
	if ((0xffffff & rand()) % 6 == 5)
		b = (b - 1) % 256;
	newc += (r << (2 * 8));
	newc += (g << (1 * 8));
	newc += (b << (0 * 8));
	u->grad = newc;
	mlx_put_image_to_window(u->mlx, u->win, u->img, 0, 0);
	// printf("%d\n", frame++);
	usleep(1000000 / 60);
}

void	game(t_data *d)
{
	t_umlx	u;

	ft_bzero(&u, sizeof(t_umlx));
	u.d = d;
	u.mlx = mlx_init();
	if (!u.mlx)
		exit_exec(&u, 1);
	u.win = mlx_new_window(u.mlx, WIN_W, WIN_H, "Cub3d");
	if (!u.win)
		exit_exec(&u, 1);
	u.img = mlx_new_image(u.mlx, WIN_W, WIN_H);
	get_addr(&u);
	// load_textures(&u);
	mlx_key_hook(u.win, hook, &u);
	mlx_loop_hook(u.mlx, (int (*)())(void *)loop, &u);
	mlx_loop(u.mlx);
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
