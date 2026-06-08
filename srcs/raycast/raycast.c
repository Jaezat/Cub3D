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
	int		ystart;
	int		steps;
	float	brightness;

	ystart = WIN_H / 2;
	steps = WIN_H / (distance * cos(ang_offset) * 2);
	if (steps > WIN_H / 2)
		steps = WIN_H;
	brightness = -(int)(256 / (100 / (distance * cos(ang_offset)) / 4
				+ 1)) << 8 & 0xff00;
	// brightness = brightness << 8;
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
				draw_column(u, line, hyp, dir);
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
	float	px;
	float	py;
	float	dx;
	float	dy;
	float	t_delta_x;
	float	t_delta_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	double	distance;

	px = u->d->px;
	py = u->d->py;
	dx = cos(dir);
	dy = sin(dir);
	float t_max_x, t_max_y;
	t_delta_x = (dx == 0) ? INFINITY : fabs(1.0 / dx);
	t_delta_y = (dy == 0) ? INFINITY : fabs(1.0 / dy);
	map_x = (int)floor(px);
	map_y = (int)floor(py);
	step_x = (dx > 0) ? 1 : -1;
	step_y = (dy > 0) ? 1 : -1;
	// Track which wall face we hit (0 for East/West, 1 for North/South)
	// This is optional, but useful if you want different wall lighting later.
	if (dx > 0)
		t_max_x = (floor(px + 1.0) - px) * t_delta_x;
	else
		t_max_x = (px - floor(px)) * t_delta_x;
	if (dy > 0)
		t_max_y = (floor(py + 1.0) - py) * t_delta_y;
	else
		t_max_y = (py - floor(py)) * t_delta_y;
	while (1)
	{
		if (map_x < 0 || map_x >= u->d->map_w || map_y < 0
			|| map_y >= u->d->map_h)
			break ;
		if (u->d->map[map_y][map_x] == '1')
		{
			// Calculate exact perpendicular distance to the wall.
			// We subtract t_delta because the loop increments *before* checking the wall.
			if (side == 0)
				distance = t_max_x - t_delta_x;
			else
				distance = t_max_y - t_delta_y;
			// put_square(u, map_y, map_x, 0xff00);
			// --- HERE IS THE CALL ---
			// 'line' is your current screen column (X coordinate)
			draw_column(u, line, distance, ang_offset);
			break ;
		}
		if (t_max_x < t_max_y)
		{
			t_max_x += t_delta_x;
			map_x += step_x;
			side = 0; // Hit a vertical grid line
		}
		else
		{
			t_max_y += t_delta_y;
			map_y += step_y;
			side = 1; // Hit a horizontal grid line
		}
	}
}

void	radar(t_umlx *u, float dir, int line, float ang_offset)
{
	float	x;
	float	y;
	float	hyp;
	float	jump_x;
	float	jump_y;

	// static int		rnd = 0;
	jump_x = cos(dir);
	jump_y = sin(dir);
	x = jump_x + rand() % u->d->map_w;
	y = jump_y + rand() % u->d->map_h;
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
				x = x - jump_x;
				y = y - jump_y;
				put_dot(u, y, x, 0xff00);
				// precision_jump(u, dir, line, ang_offset, x, y);
				break ;
			}
		// put_dot(u, y, x, 0xff00);
		// put_square(u, (float)0.5 + WIN_H / u->d->map_h * (int)y / (WIN_H
		// 		/ u->d->map_h), (float)0.5 + WIN_W / u->d->map_w * (int)x
		// 	/ (WIN_W / u->d->map_w), 0x008000);
		// put_dot(u, y, x, 0x0000ff);
		x = x + jump_x;
		y = y + jump_y;
	}
}

void	apperture(t_umlx *u)
{
	float			ang_offset;
	int				line;
	static float	radar_ang = 0;

	line = 0;
	ang_offset = -35 * M_PI / 180;
	while (line < WIN_W)
	{
		radar_ang = rand() * M_PI / 180;
		// find_block(u, u->d->dir + ang_offset, line, ang_offset);
		radar(u, radar_ang, line, radar_ang);
		// printf("%f\n", ang_offset);
		ang_offset = ang_offset + (((float)71 / WIN_W) * M_PI / 180);
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
	// int	w;
	// int	h;

	// // float	x;
	// // float	y;
	// h = 0;
	// while (h <= WIN_H)
	// {
	// 	w = 0;
	// 	while (w <= WIN_W)
	// 	{
	// 		if (h < WIN_H / 2)
	// 			u->img_data.addr[WIN_W * h + w] = u->d->sky;
	// 		else
	// 			u->img_data.addr[WIN_W * h + w] = u->d->ground;
	// 		w++;
	// 	}
	// 	h++;
	// }
	ft_bzero(u->img_data.addr, WIN_H * WIN_W * 4);
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
