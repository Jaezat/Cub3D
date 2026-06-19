#include "main.h"

// this can be improved to have less math
void	draw_col(t_env *e, t_raycam *rc, t_ray *r)
{
	int		mid;
	int		steps;
	int		col;
	float	max_dist;
	float	dist;
	int		intensity;

	mid = WIN_H / 2;
	steps = WIN_H / (r->cam_dist) / 2;
	max_dist = 30.0f;
	dist = r->cam_dist;
	if (dist > max_dist)
		dist = max_dist;
	if (dist < 0.0f)
		dist = 0.0f;
	intensity = (int)(200.0f * (1.0f - (dist / max_dist)));
	col = intensity << 8;
	while (steps >= 0)
	{
		if (((mid - steps) * WIN_W + rc->x) < WIN_H * WIN_W - 1)
			if (((mid - steps) * WIN_W + rc->x) >= 0)
				e->umlx.img_data.addr[(int)((mid - steps) * WIN_W
						+ rc->x)] = col;
		if (((mid + steps - 1) * WIN_W + rc->x) < WIN_H * WIN_W - 1)
			if (((mid + steps - 1) * WIN_W + rc->x) >= 0)
				e->umlx.img_data.addr[(int)((mid + steps - 1) * WIN_W
						+ rc->x)] = col;
		steps--;
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
		// put_dot(e, rc.ray_y + e->data->py, rc.ray_x + e->data->px, 0xff0000);
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
	ft_int_set(img, WIN_W * WIN_H, 0);
	hr = WIN_H / e->data->map_h;
	wr = WIN_W / e->data->map_w;
	ft_int_set(img, WIN_W * WIN_H / 2, e->data->sky);
	ft_int_set(img+WIN_W * WIN_H / 2, WIN_W * WIN_H / 2, e->data->ground);
	put_camera(e);
}

// void	load_textures(t_umlx *u)
// {
// 	t_data	*d;
// 	t_img	*img;
// 	int		i;
// 	char	**arr;

// 	d = u->d;
// 	arr = (char *[]){d->no, d->so, d->ea, d->we};
// 	i = 0;
// 	while (i < 4)
// 	{
// 		img = &d->imgs[i];
// 		img->ptr = mlx_xpm_file_to_image(u->mlx, arr[i], &img->w, &img->h);
// 		if (!img->ptr)
// 		{
// 			ft_puterr("Error\nFailed to load textures\n");
// 			exit_exec(u, 1);
// 		}
// 		i++;
// 	}
// }