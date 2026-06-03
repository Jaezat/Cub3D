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

void	draw_column(t_umlx *u, int x, double distance)
{
	int	ystart;
	int	steps;
	int	brightness;

	ystart = WIN_H / 2;
	steps = WIN_H / (distance * 2) + 50;
	brightness = (int)(255 / distance) << 8 & (rand() & 0x00ff00);
	while (steps)
	{
		if (((ystart - steps) * WIN_W + x) < WIN_H * WIN_W - 1)
			if (((ystart - steps) * WIN_W + x) >= 0)
				u->img_data.addr[(ystart - steps) * WIN_W
					+ x] = brightness & 0x00ff00;
		if (((ystart + steps - 1) * WIN_W + x) < WIN_H * WIN_W - 1)
			if (((ystart + steps - 1) * WIN_W + x) >= 0)
				u->img_data.addr[(ystart + steps - 1) * WIN_W
					+ x] = brightness & 0x00ff00;
		steps--;
	}
}

void	find_block(t_umlx *u, float dir, int line)
{
	float	x;
	float	y;
	float	offset;
	float	hypotenuse;

	offset = 10;
	x = cos(dir) / offset + u->d->px;
	y = sin(dir) / offset + u->d->py;
	while (1)
	{
		if (x < 0 || x >= WIN_W)
			break ;
		if (y < 0 || y >= WIN_H)
			break ;
		if (y >= 0 && x >= 0)
			if ((int)y <= u->d->map_h && (int)x <= u->d->map_w)
				if (u->d->map[(int)y][(int)x] == '1')
				{
					hypotenuse = (y - u->d->py) * (y - u->d->py) + (x
							- u->d->px) * (x - u->d->px);
					// put_dot(u, y, x, 0x0000ff);
					draw_column(u, line, sqrt(hypotenuse));
					break ;
				}
		x = x + cos(dir) / offset;
		y = y + sin(dir) / offset;
	}
}

void	apperture(t_umlx *u)
{
	float	ang_offset;
	int		line;

	line = 0;
	ang_offset = -35 * M_PI / 180;
	while (line < WIN_W)
	{
		find_block(u, u->d->dir + ang_offset, line);
		ang_offset = ang_offset + (((float)70 / WIN_W) * M_PI / 180);
		line++;
	}
}

void	put_background(t_umlx *u)
{
	int	w;
	int	h;

	w = 0;
	while (w < WIN_W)
	{
		h = 0;
		while (h < WIN_H)
		{
			if (h < WIN_H / 2)
				u->img_data.addr[WIN_W * h + w] = u->d->sky;
			else
				u->img_data.addr[WIN_W * h + w] = u->d->ground;
			h++;
		}
		w++;
	}
	apperture(u);
	put_square(u, u->d->py, u->d->px, 0xff0000);
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
