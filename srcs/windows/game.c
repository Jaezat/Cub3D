#include "main.h"

void	get_addr(t_umlx *u)
{
	t_img_data	*im;

	im = &u->img_data;
	im->addr = (int *)mlx_get_data_addr(u->img, &im->bpp, &im->line_s,
			&im->endian);
}

void	safe_pix_put(t_umlx *u, int byte, int color)
{
	if (byte >= 0 && byte < WIN_H * WIN_W)
		u->img_data.addr[byte] = color;
}

void	put_square(t_umlx *u, float hf, float wf, int color)
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
			if ((h + i) > 0 && (h + i) < (WIN_H + i))
				if ((w + j) > 0 && (w + j) < (WIN_W + j))
					safe_pix_put(u, (int)(WIN_W * (h + i) + w + j), color);
			j++;
		}
		i++;
	}
}

void	single_ray(t_umlx *u)
{
	float	x;
	float	y;

	x = sin(u->d->dir) + u->d->px;
	y = cos(u->d->dir) + u->d->py;
	put_square(u, y, x, 0x0000ff);
}

void	paint_put(t_umlx *u)
{
	int	w;
	int	h;
	int	wr;
	int	hr;

	hr = WIN_H / u->d->map_h;
	wr = WIN_W / u->d->map_w;
	w = 0;
	while (w < WIN_W)
	{
		h = 0;
		while (h < WIN_H)
		{
			if (h % hr == 0 || (w % wr == 0))
				u->img_data.addr[WIN_W * h + w] = 0xffffff;
			else if (u->d->map[(h / hr)][(w / wr)] == '1')
				u->img_data.addr[WIN_W * h + w] = 0x303030;
			else
				u->img_data.addr[WIN_W * h + w] = 0x808080;
			h++;
		}
		w++;
	}
	put_square(u, u->d->py, u->d->px, 0xff0000);
	single_ray(u);
	usleep(1000000 / 60);
}

#define MOV_INC 0.25
#define ANG_INC 0.2

void	key_press(int keycode, void *param)
{
	t_game	*env;
	t_data	*data;
	t_umlx	*umlx;

	env = param;
	data = env->u.d;
	umlx = &env->u;
	(void)umlx;
	if (keycode == K_W)
		data->py -= MOV_INC;
	if (keycode == K_S)
		data->py += MOV_INC;
	if (keycode == K_A)
		data->px -= MOV_INC;
	if (keycode == K_D)
		data->px += MOV_INC;
	if (keycode == K_RIGHT)
		data->dir -= ANG_INC;
	if (keycode == K_LEFT)
		data->dir += ANG_INC;
}

typedef int				(*t_clean)();

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
