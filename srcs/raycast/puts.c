#include "main.h"

// this whole function needs protection
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
	i = -2;
	while (i < 3)
	{
		j = -2;
		while (j < 3)
		{
			if ((h + i) > 0 && (h + i) < (WIN_H + i))
				if ((w + j) > 0 && (w + j) < (WIN_W + j))
					safe_pix_put(u, (int)(WIN_W * (h + i) + w + j), color);
			j++;
		}
		i++;
	}
}

void	put_dot(t_umlx *u, float hf, float wf, int color)
{
	int	h;
	int	w;

	h = hf * (WIN_H / u->d->map_h);
	w = wf * (WIN_W / u->d->map_w);
	if (h > 0 && h < (WIN_H))
		if (w > 0 && w < (WIN_W))
			safe_pix_put(u, (int)(WIN_W * h + w), color);
}

void	add_pigment(t_umlx *u, float hf, float wf, int color)
{
	int	h;
	int	w;

	h = hf * (WIN_H / u->d->map_h);
	w = wf * (WIN_W / u->d->map_w);
	if (h > 0 && h < (WIN_H))
		if (w > 0 && w < (WIN_W))
		{
			if ((int)(WIN_W * h + w) >= 0 && (int)(WIN_W * h + w) < WIN_H * WIN_W)
				u->img_data.addr[(int)(WIN_W * h + w)] += color;
		}
}

void	single_ray(t_umlx *u)
{
	float	x;
	float	y;

	x = cos(u->d->dir) + u->d->px;
	y = sin(u->d->dir) + u->d->py;
	while (1)
	{
		if (x < 0 || x >= WIN_W)
			break ;
		if (y < 0 || y >= WIN_H)
			break ;
		if ((u->img_data.addr[(int)(WIN_W * y + x)] == 0))
		{
			put_square(u, y, x, 0xff0000);
		}
		else
			put_square(u, y, x, 0x0000ff);
		x = x + cos(u->d->dir);
		y = y + sin(u->d->dir);
	}
}
