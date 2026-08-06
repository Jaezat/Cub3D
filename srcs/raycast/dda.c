#include "main.h"

int	wall_no(t_ray *r)
{
	// this looks wrong 
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

void	pixel_put_tex(t_env *e, t_col_draw *col, t_raycam *rc, t_ray *r)
{
	int	tex_y;
	int	color;

	tex_y = (int)col->tex_pos & (e->data->imgs[r->wall_id].h - 1);
	col->tex_pos += col->step;
	color = *(int *)(e->data->imgs[r->wall_id].addr
			+ (e->data->imgs[r->wall_id].h * tex_y + col->tex_x));
	if (r->side == 1)
		color = (color >> 1) & 0x7f7f7f;
	e->umlx.img_data.addr[(int)(col->i * WIN_W + rc->x)] = color;	
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
	if (rc->r_dir_x < 0)
	{
		r->x_vec_dir = -1;
		r->curr_x = (e->data->px - r->map_x) * r->x_jump;
	}
	else
	{
		r->x_vec_dir = 1;
		r->curr_x = (r->map_x + 1.0 - e->data->px) * r->x_jump;
	}
	if (rc->r_dir_y < 0)
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
