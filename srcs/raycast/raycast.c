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

void	draw_column(t_umlx *u, int x, double distance, float ang_offset)
{
	int	ystart;
	int	steps;
	int	brightness;

	ystart = WIN_H / 2;
	steps = WIN_H / (distance * cos(ang_offset));
	brightness = (int)(255 / distance) << 8 & 0x00ff00;
	while (steps >= 0)
	{
		if (((ystart - steps) * WIN_W + x) < WIN_H * WIN_W - 1)
			if (((ystart - steps) * WIN_W + x) >= 0)
				u->img_data.addr[(ystart - steps) * WIN_W + x] = brightness;
		if (((ystart + steps - 1) * WIN_W + x) < WIN_H * WIN_W - 1)
			if (((ystart + steps - 1) * WIN_W + x) >= 0)
				u->img_data.addr[(ystart + steps - 1) * WIN_W + x] = brightness;
		steps--;
	}
}

void	precision_jump(t_umlx *u, float dir, int line, float ang_offset,
		float x, float y)
{
	float	hyp;
	float	jump;

	jump = 1000;
	while (1)
	{
		if (x < 0 || x >= WIN_W)
			break ;
		if (y < 0 || y >= WIN_H)
			break ;
		if ((int)y < u->d->map_h && (int)x < u->d->map_w)
			if (u->d->map[(int)y][(int)x] == '1')
			{
				hyp = hypot(y - u->d->py, x - u->d->px);
				(void)hyp;
				(void)ang_offset;
				(void)line;
				put_dot(u, y, x, 0xff0000);
				// usleep(1);
				draw_column(u, line, hyp, ang_offset);
				break ;
			}
		// put_square(u, (float)0.5 + WIN_H / u->d->map_h * (int)y / (WIN_H
		// 		/ u->d->map_h), (float)0.5 + WIN_W / u->d->map_w * (int)x
		// 	/ (WIN_W / u->d->map_w), 0x008000);
		// put_dot(u, y, x, 0x0000ff);
		x = x + cos(dir) / jump;
		y = y + sin(dir) / jump;
	}
}

void	find_block(t_umlx *u, float dir, int line, float ang_offset)
{
	float	x;
	float	y;
	float	hyp;
	float	jump;

	jump = 10;
	x = cos(dir) / jump + u->d->px;
	y = sin(dir) / jump + u->d->py;
	while (1)
	{
		if (x < 0 || x >= WIN_W)
			break ;
		if (y < 0 || y >= WIN_H)
			break ;
		if ((int)y < u->d->map_h && (int)x < u->d->map_w)
			if (u->d->map[(int)y][(int)x] == '1')
			{
				hyp = hypot(y - u->d->py, x - u->d->px);
				(void)hyp;
				(void)ang_offset;
				(void)line;
				put_dot(u, y, x, 0);
				x = x - cos(dir) / jump;
				y = y - sin(dir) / jump;
				// precision_jump(u, dir, line, ang_offset, x, y);
				break ;
			}
		// put_square(u, (float)0.5 + WIN_H / u->d->map_h * (int)y / (WIN_H
		// 		/ u->d->map_h), (float)0.5 + WIN_W / u->d->map_w * (int)x
		// 	/ (WIN_W / u->d->map_w), 0x008000);
		// put_dot(u, y, x, 0x0000ff);
		x = x + cos(dir) / jump;
		y = y + sin(dir) / jump;
	}
}

void	radar(t_umlx *u, float dir, int line, float ang_offset)
{
	float	x;
	float	y;
	float	hyp;
	float	jump;
	// static int		rnd = 0;

	jump = 1;
	
	x = cos(dir) / jump + rand() % u->d->map_w;
	y = sin(dir) / jump + rand() % u->d->map_h;
	// rnd = rand();
	while (1)
	{
		// rnd = rand();
		if (x < 0 || x >= WIN_W)
			break ;
		if (y < 0 || y >= WIN_H)
			break ;
		if ((int)y < u->d->map_h && (int)x < u->d->map_w)
			if (u->d->map[(int)y][(int)x] == '1')
			{
				hyp = hypot(y - rand() % u->d->map_h, x - rand() % u->d->map_w);
				(void)hyp;
				(void)ang_offset;
				(void)line;
				// put_dot(u, y, x, rnd);
				x = x - cos(dir) / jump;
				y = y - sin(dir) / jump;
				precision_jump(u, dir, line, ang_offset, x, y);
				break ;
			}
		// put_dot(u, y, x, rnd);
		// put_square(u, (float)0.5 + WIN_H / u->d->map_h * (int)y / (WIN_H
		// 		/ u->d->map_h), (float)0.5 + WIN_W / u->d->map_w * (int)x
		// 	/ (WIN_W / u->d->map_w), 0x008000);
		// put_dot(u, y, x, 0x0000ff);
		
		x = x + cos(dir) / jump;
		y = y + sin(dir) / jump;
	}
	
}

void	apperture(t_umlx *u)
{
	float			ang_offset;
	static float	radar_ang = 0;
	int				line;

	line = 0;
	ang_offset = -35 * M_PI / 180;
	while (line < WIN_W)
	{
		radar(u, radar_ang, line, ang_offset);
		// find_block(u, u->d->dir + ang_offset, line, ang_offset);
		ang_offset = ang_offset + (((float)70 / WIN_W) * M_PI / 180);
		radar_ang = radar_ang + rand();
		line++;
	}
}

void	project(t_umlx *u)
{
	float	x;
	float	y;
	int		i;

	x = cos(u->d->dir);
	y = sin(u->d->dir);
	i = 1;
	while (i < 5)
	{
		put_square(u, (int)(y * i + u->d->py), (int)(x * i + u->d->px),
			0x007000);
		i++;
	}
}

void	put_background(t_umlx *u)
{
	int	w;
	int	h;

	// float	x;
	// float	y;
	h = 0;
	while (h < WIN_H)
	{
		w = 0;
		while (w < WIN_W)
		{
			u->img_data.addr[WIN_W * h + w] = 0;
			// if (h < WIN_H / 2)
			// 	u->img_data.addr[WIN_W * h + w] = u->d->sky;
			// else
			// 	u->img_data.addr[WIN_W * h + w] = u->d->ground;
			w++;
		}
		h++;
	}
	apperture(u);
	// project(u);
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
