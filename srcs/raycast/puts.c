#include "main.h"

// this is better because it has protection
void	*get_addr_tex(t_img_data *img)
{
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->line_s,
			&img->endian);
	return (img->addr);
}

// // this whole function needs protection
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

void	put_square(t_env *e, float hf, float wf, int color)
{
	int	i;
	int	h;
	int	w;
	int	j;

	h = hf * (WIN_H / e->data->map_h);
	w = wf * (WIN_W / e->data->map_w);
	i = -2;
	while (i < 3)
	{
		j = -2;
		while (j < 3)
		{
			if ((h + i) > 0 && (h + i) < (WIN_H + i))
				if ((w + j) > 0 && (w + j) < (WIN_W + j))
					safe_pix_put(&e->umlx, (int)(WIN_W * (h + i) + w + j), color);
			j++;
		}
		i++;
	}
}

void	put_dot(t_env *e, float hf, float wf, int color)
{
	int	h;
	int	w;

	h = hf * (WIN_H / e->data->map_h);
	w = wf * (WIN_W / e->data->map_w);
	if (h > 0 && h < (WIN_H))
		if (w > 0 && w < (WIN_W))
			safe_pix_put(&e->umlx, (int)(WIN_W * h + w), color);
}
