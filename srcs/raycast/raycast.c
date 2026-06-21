#include "main.h"

// in case of no return which is impossible i think???
int	wall_no(t_ray *r)
{
	if (r->side == 0)
	{
		if (r->x_vec_dir > 0)
			return (WE);
		else
			return (EA);
	}
	else
	{
		if (r->y_vec_dir > 0)
			return (NO);
		else
			return (SO);
	}
}

void	pixel_put_tex(t_env *e, t_col_draw *col, t_raycam *rc, t_ray *r,
		int texX, float *texPos, float step)
{
	int	texY;
	int	color;

	texY = (int)*texPos & (e->data->imgs[r->wall_id].h - 1);
	*texPos += step;
	color = *(int *)(e->data->imgs[r->wall_id].addr
			+ (e->data->imgs[r->wall_id].h * texY + texX));
	// if (r->side == 1)
	// 	color = (color >> 1) & 0x7f7f7f;
	e->umlx.img_data.addr[(int)(col->i * WIN_W + rc->x)] = color;
}

void	draw_col(t_env *e, t_raycam *rc, t_ray *r)
{
	t_col_draw	col;
	int			texX;
	float		step;
	float		texPos;

	r->wall_id = wall_no(r);
	col.tex_res = e->data->imgs[r->wall_id].w;
	col.steps = (int)(WIN_H / r->cam_dist);
	col.start = -col.steps / 2 + WIN_H / 2;
	if (col.start < 0)
		col.start = 0;
	col.end = col.steps / 2 + WIN_H / 2;
	if (col.end >= WIN_H)
		col.end = WIN_H - 1;
	if (r->side == 0)
		col.wall_col = e->data->py + r->cam_dist * rc->ray_y;
	else
		col.wall_col = e->data->px + r->cam_dist * rc->ray_x;
	col.wall_col -= floor(col.wall_col);
	texX = (int)(col.wall_col * col.tex_res);
	if ((r->side == 0 && rc->ray_x < 0) || (r->side == 1 && rc->ray_y > 0))
		texX = col.tex_res - texX - 1;
	step = 1.0f * col.tex_res / col.steps;
	if (col.start > 0)
		col.i = col.start;
	else
		col.i = 0;
	texPos = (col.i - WIN_H / 2 + col.steps / 2) * step;
	while (col.i < col.end)
	{
		pixel_put_tex(e, &col, rc, r, texX, &texPos, step);
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
		r.x_jump = INFINITY;
	else
		r.x_jump = fabs(1 / rc.ray_x);
	if (rc.ray_y == 0)
		r.y_jump = INFINITY;
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
		put_dot(e, rc.ray_y + e->data->py, rc.ray_x + e->data->px, 0xff00);
		// put_dot(e, rc.cam_y * rc.col + e->data->py, rc.cam_x * rc.col
		// + e->data->px, 0xff00);
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
	put_camera(e);
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
		if (img->w != img->h || img->w < 1)
		{
			ft_puterr("Error\nTextures need to be perfectly squared\n");
			exit_exec(e, 1);
		}
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
