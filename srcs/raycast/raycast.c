#include "main.h"

void	pick_tex_col(t_env *e, t_col_draw *col, t_raycam *rc, t_ray *r)
{
	int		texX;
	float	step;
	float	texPos;
	int		texY;
	int		color;

	// 1. Calculate where the wall was hit (X coordinate on the texture)
	if (r->side == 0)
		col->wall_col = r->map_y + r->cam_dist * rc->ray_y;
	else
		col->wall_col = r->map_x + r->cam_dist * rc->ray_x;
	col->wall_col -= floor((col->wall_col));
	// 2. Get the texture X coordinate
	texX = (int)(col->wall_col * col->tex_res);
	if (r->side == 0 && rc->ray_x > 0)
		texX = col->tex_res - texX - 1;
	if (r->side == 1 && rc->ray_y < 0)
		// Fixed: tutorial usually checks ray_y for side 1
		texX = col->tex_res - texX - 1;
	// 3. Calculate texture Y coordinate based on current screen Y (col->i)
	step = 1.0 * col->tex_res / col->steps;
	// Calculate the texture position relative to the current pixel row (col->i)
	texPos = (col->i - WIN_H / 2 + col->steps / 2) * step;
	texY = (int)texPos & (col->tex_res - 1);
	// 4. Fetch the color from your actual MLX texture image
	// Assumes your texture data pointer is structured like a flat 1D array of ints
	// color = *(int *)(e->data->imgs[0].ptr + (col->tex_res * texY + texX));
	color = 0;
	// 5. Apply shadows for Y-axis walls
	if (r->side == 1)
		color = (color >> 1) & 8355711; // Darken the color
	// 6. Write DIRECTLY to your MLX image address instead of 'buffer'
	e->umlx.img_data.addr[(int)(col->i * WIN_W + rc->x)] = color;
}

// this can be improved to have less math
void	draw_col(t_env *e, t_raycam *rc, t_ray *r)
{
	t_col_draw	col;

	col.tex_res = 512;
	col.steps = (int)(WIN_H / r->cam_dist);
	col.start = -col.steps / 2 + WIN_H / 2;
	if (col.start < 0)
		col.start = 0;
	col.end = col.steps / 2 + WIN_H / 2;
	if (col.end >= WIN_H)
		col.end = WIN_H - 1;
	col.i = col.start;
	while (col.i < col.end)
	{
		pick_tex_col(e, &col, rc, r);
		col.i++;
	}
}

void	find_hit(t_env *e, t_raycam *rc, t_ray *r)
{
	while (r->hit == 0)
	{
		if (r->curr_x < r->curr_y)
		{
			r->curr_x += r->x_jump;
			r->map_x += r->x_vec_dir;
			r->side = 0;
		}
		else
		{
			r->curr_y += r->y_jump;
			r->map_y += r->y_vec_dir;
			r->side = 1;
		}
		if (e->data->map[r->map_y][r->map_x] == '1')
		{
			if (r->side == 0)
				r->cam_dist = (r->curr_x - r->x_jump);
			else
				r->cam_dist = (r->curr_y - r->y_jump);
			draw_col(e, rc, r);
			r->hit = 1;
		}
	}
}

void	set_jumps(t_env *e, t_raycam *rc, t_ray *r)
{
	if (rc->ray_x < 0)
	{
		r->x_vec_dir = -1;
		r->curr_x = (e->data->px - r->map_x) * r->x_jump;
	}
	else
	{
		r->x_vec_dir = 1;
		r->curr_x = (r->map_x + 1.0 - e->data->px) * r->x_jump;
	}
	if (rc->ray_y < 0)
	{
		r->y_vec_dir = -1;
		r->curr_y = (e->data->py - r->map_y) * r->y_jump;
	}
	else
	{
		r->y_vec_dir = 1;
		r->curr_y = (r->map_y + 1.0 - e->data->py) * r->y_jump;
	}
}

void	shoot(t_env *e, t_raycam rc)
{
	t_ray	r;

	r.map_x = (int)e->data->px;
	r.map_y = (int)e->data->py;
	r.hit = 0;
	if (rc.ray_x == 0)
		r.x_jump = 1e30;
	else
		r.x_jump = fabs(1 / rc.ray_x);
	if (rc.ray_y == 0)
		r.y_jump = 1e30;
	else
		r.y_jump = fabs(1 / rc.ray_y);
	set_jumps(e, &rc, &r);
	find_hit(e, &rc, &r);
}

void	put_camera(t_env *e)
{
	t_raycam	rc;

	rc.cam_x = -e->data->dir_y * 0.66;
	rc.cam_y = e->data->dir_x * 0.66;
	rc.x = 0;
	while (rc.x < WIN_W)
	{
		rc.col = 2 * rc.x / (float)WIN_W - 1;
		rc.ray_x = e->data->dir_x + rc.cam_x * rc.col;
		rc.ray_y = e->data->dir_y + rc.cam_y * rc.col;
		shoot(e, rc);
		rc.x++;
	}
	put_square(e, e->data->py, e->data->px, 0xff0000);
}

void	put_background(t_env *e)
{
	int	*img;
	int	i;
	int	hr;
	int	wr;
	int	j;

	i = 0;
	img = e->umlx.img_data.addr;
	hr = WIN_H / e->data->map_h;
	wr = WIN_W / e->data->map_w;
	ft_int_set(img, WIN_W * WIN_H / 2, e->data->sky);
	ft_int_set(img + WIN_W * WIN_H / 2, WIN_W * WIN_H / 2, e->data->ground);
	mlx_put_image_to_window(e->umlx.mlx, e->umlx.win, e->data->imgs[1].img, 0,
		0);
	// put_camera(e);
}

void	*get_addr_tex(t_img_data *img);

void	load_textures(t_env *e)
{
	t_data		*d;
	t_img_data	*img;
	int			i;
	char		**arr;

	d = e->data;
	arr = (char *[]){d->no, d->so, d->ea, d->we};
	i = 0;
	while (i < 4)
	{
		img = &d->imgs[i];
		img->img = mlx_xpm_file_to_image(e->umlx.mlx, arr[i], &img->w, &img->h);
		if (!img->img)
		{
			ft_puterr("Error\nFailed to load textures\n");
			exit_exec(e, 1);
		}
		if (!get_addr_tex(img))
		{
			ft_puterr("Error\nFailed to failed to get texture addresses\n");
			exit_exec(e, 1);
		};
		i++;
	}
}
