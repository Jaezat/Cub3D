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

	// int	start;
	ystart = WIN_H / 2;
	// start = x;
	(void)distance;
	int steps = WIN_H / distance;
	while (ystart >= 0 && steps)
	{
		// printf("here %d\n", ystart);
		// usleep(1000000/5);
		if (((ystart - steps) * WIN_W + x) < WIN_H * WIN_W - 1)
			if (((ystart - steps) * WIN_W + x) >= 0)
				u->img_data.addr[(ystart - steps) * WIN_W + x] = 0x808080;
		if (((ystart + steps) * WIN_W + x) < WIN_H * WIN_W - 1)
			if (((ystart + steps) * WIN_W + x) >= 0)
				u->img_data.addr[(ystart + steps) * WIN_W + x] = 0x808080;
		ystart++;
		steps--;
	}
}

void	find_block(t_umlx *u, float dir, int line)
{
	float	x;
	float	y;
	float	offset;
	float	hypotenuse;

	offset = 1;
	x = cos(dir) / offset + u->d->px;
	y = sin(dir) / offset + u->d->py;
	while (1)
	{
		if (x < 0 || x >= WIN_W)
			break ;
		if (y < 0 || y >= WIN_H)
			break ;
		if ((int)y >= 0 && (int)x >= 0)
			if ((int)y <= u->d->map_h && (int)x <= u->d->map_w)
				if (u->d->map[(int)y][(int)x] == '1')
				{
					hypotenuse = (y - u->d->py) * (y - u->d->py) + (x
							- u->d->px) * (x - u->d->px);
					put_square(u, y, x, 0x0000ff);
					draw_column(u, (int)(line * WIN_W / 70),
						sqrt(hypotenuse));
					break ;
				}
		x = x + cos(dir) / offset;
		y = y + sin(dir) / offset;
	}
}

void	apperture(t_umlx *u)
{
	float	ang_offset;
	int		lines;

	lines = 71;
	ang_offset = -35 * M_PI / 180;
	while (lines--)
	{
		find_block(u, u->d->dir + ang_offset, lines);
		ang_offset = ang_offset + (1 * M_PI / 180);
	}
}

void	put_background(t_umlx *u)
{
	int	w;
	int	h;

	// int	wr;
	// int	hr;
	// hr = WIN_H / u->d->map_h;
	// wr = WIN_W / u->d->map_w;
	w = 0;
	while (w < WIN_W)
	{
		h = 0;
		while (h < WIN_H)
		{
			u->img_data.addr[WIN_W * h + w] = 0;
			// if (h % hr == 0 || (w % wr == 0))
			// 	u->img_data.addr[WIN_W * h + w] = 0;
			// else if (u->d->map[(h / hr)][(w / wr)] == '1')
			// 	u->img_data.addr[WIN_W * h + w] = u->d->ground;
			// else
			// 	u->img_data.addr[WIN_W * h + w] = u->d->sky;
			h++;
		}
		w++;
	}
	put_square(u, u->d->py, u->d->px, 0xff0000);
	apperture(u);
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
