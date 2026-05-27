#include "main.h"

void	get_addr(t_umlx *u)
{
	t_img_data	*im;

	im = &u->img_data;
	im->addr = (int *)mlx_get_data_addr(u->img, &im->bpp, &im->line_s,
			&im->endian);
}

void	put_player(t_umlx *u, float hf, float wf)
{
	int	i;
	int	h;
	int	w;
	int	j;

	h = hf * (WIN_H / u->d->map_h);
	w = wf * (WIN_W / u->d->map_w);
	i = -4;
	while (i < 5)
	{
		j = -4;
		while (j < 5)
		{
			if ((h - i) > 0 && (h + i) < (WIN_H + i))
				if ((w - j) > 0 && (w + j) < (WIN_W + j))
					u->img_data.addr[(int)(WIN_W * (h + i) + w + j)] = 0xff0000;
			j++;
		}
		i++;
	}
}

void	paint_put(t_umlx *u)
{
	int		w;
	int		h;
	float	wr;
	float	hr;

	w = 0;
	hr = ((float)WIN_H / u->d->map_h);
	wr = ((float)WIN_W / u->d->map_w);
	while (w < WIN_W)
	{
		h = 0;
		while (h < WIN_H)
		{
			if (h % (int)(hr) == 0 || (w % (int)wr == 0))
				u->img_data.addr[WIN_W * h + w] = 0xffffff;
			else if (u->d->map[(int)(h / (hr))][(int)(w / (wr))] == '1')
				u->img_data.addr[WIN_W * h + w] = 0x303030;
			else
				u->img_data.addr[WIN_W * h + w] = 0x808080;
			h++;
		}
		w++;
	}
	put_player(u, u->d->py, u->d->px);
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
