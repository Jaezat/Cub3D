#include "main.h"

// void	multi_ray(t_umlx *u)
// {
// 	int	i;

// 	i = 0;
//
// 	while (i < 10)
// 	{
// 		u->d->dir += 0.02;
// 		single_ray(u);
// 		i++;
// 	}
// 	u->d->dir -= 0.2;
// }

void	find_block(t_umlx *u)
{
	float	x;
	float	y;
	float	offset;

	offset = 1;
	x = cos(u->d->dir) / offset + u->d->px;
	y = sin(u->d->dir) / offset + u->d->py;
	while (1)
	{
		if (x < 0 || x >= WIN_W)
			break ;
		if (y < 0 || y >= WIN_H)
			break ;
		put_dot(u, y, x, 0x0000ff);
		if ((int)y >= 0 && (int)x >= 0)
			if ((int)y <= u->d->map_h && (int)x <= u->d->map_w)
				if (u->d->map[(int)y][(int)x] == '1')
				{
					put_square(u, (int)y + 0.5, (int)x + 0.5, 0x00ff00);
					break ;
				}
		x = x + cos(u->d->dir) / offset;
		y = y + sin(u->d->dir) / offset;
	}
}

void	put_background(t_umlx *u)
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
				u->img_data.addr[WIN_W * h + w] = 0;
			else if (u->d->map[(h / hr)][(w / wr)] == '1')
				u->img_data.addr[WIN_W * h + w] = u->d->ground;
			else
				u->img_data.addr[WIN_W * h + w] = u->d->sky;
			h++;
		}
		w++;
	}
	put_square(u, u->d->py, u->d->px, 0xff0000);
	find_block(u);
}

void	load_textures(t_umlx *u)
{
	t_data	*d;
	t_img	*img;
	int		i;
	char	**arr;

	d = u->d;
	arr = (char *[]){d->no, d->so, d->ea, d->we};
	i = 0;
	while (i < 4)
	{
		img = &d->imgs[i];
		img->ptr = mlx_xpm_file_to_image(u->mlx, arr[i], &img->w, &img->h);
		if (!img->ptr)
		{
			ft_puterr("Error\nFailed to load textures\n");
			exit_exec(u, 1);
		}
		i++;
	}
}
