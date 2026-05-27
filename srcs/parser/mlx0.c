#include "main.h"

void	get_addr(t_umlx *u)
{
	t_img_data	*im;

	im = &u->img_data;
	im->addr = (int *)mlx_get_data_addr(u->img, &im->bpp, &im->line_s,
			&im->endian);
	if (im->endian)
		printf("this\n");
	else
		printf("that\n");
}

void	put_player(t_umlx *u, float hf, float wf)
{
	int	i;
	int	j;
	int	h;
	int	w;

	h = hf * (WIN_H / u->d->map_h);
	w = wf * (WIN_W / u->d->map_w);
	i = 0;
	while (i < 10)
	{
		if ((h - i) > 0)
			u->img_data.addr[WIN_W * (h - i) + w] = 0xff0000;
		if ((h + i) < (WIN_H - 1))
			u->img_data.addr[WIN_W * (h + i) + w] = 0xff0000;
		i++;
	}
	j = 0;
	while (j < 10)
	{
		if ((w - j) > 0)
			u->img_data.addr[WIN_W * h + (w - j)] = 0xff0000;
		if ((w + j) < (WIN_W - 1))
			u->img_data.addr[WIN_W * h + (w + j)] = 0xff0000;
		j++;
	}
}

void	paint_put(t_umlx *u)
{
	int	w;
	int	h;
	int	wr;
	int	hr;

	wr = 0;
	hr = 0;
	w = 0;
	while (w < WIN_W)
	{
		wr = (WIN_W / u->d->map_w);
		h = 0;
		while (h < WIN_H)
		{
			hr = (WIN_H / u->d->map_h);
			if (u->d->map[h / (hr + 1)][w / (wr + 1)] == '1')
				u->img_data.addr[WIN_W * h + w] = u->d->sky;
			else
				u->img_data.addr[WIN_W * h + w] = u->d->ground;
			h++;
		}
		w++;
	}
	put_player(u, u->d->py, u->d->px);
	mlx_put_image_to_window(u->mlx, u->win, u->img, 0, 0);
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
	u.win = mlx_new_window(u.mlx, WIN_W, WIN_H, "Cub3D");
	if (!u.win)
		exit_exec(&u, 1);
	u.img = mlx_new_image(u.mlx, WIN_W, WIN_H);
	get_addr(&u);
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
