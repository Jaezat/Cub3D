#include <main.h>

void	draw_col_conditions(t_env *e, t_raycam *rc, t_ray *r, t_col_draw *col)
{
	if (col->start < 0)
		col->start = 0;
	col->end = col->steps / 2 + WIN_H / 2;
	if (col->end >= WIN_H)
		col->end = WIN_H - 1;
	// i dont know about this one
	if (r->side == 0)
		col->wall_col = e->data->py + r->cam_dist * rc->ray_y;
	else
		col->wall_col = e->data->px + r->cam_dist * rc->ray_x;
	col->wall_col -= floor(col->wall_col);
	col->tex_x = (int)(col->wall_col * col->tex_res);
	if ((r->side == 0 && rc->ray_x < 0) || (r->side == 1 && rc->ray_y > 0))
		col->tex_x = col->tex_res - col->tex_x - 1;
	col->step = 1.0f * col->tex_res / col->steps;
	if (col->start > 0)
		col->i = col->start;
	else
		col->i = 0;
}

void	draw_col(t_env *e, t_raycam *rc, t_ray *r)
{
	t_col_draw	col;

	r->wall_id = wall_no(r);
	col.tex_res = e->data->imgs[r->wall_id].w;
	col.steps = (int)(WIN_H / r->cam_dist);
	col.start = -col.steps / 2 + WIN_H / 2;
	draw_col_conditions(e, rc, r, &col);
	col.tex_pos = (col.i - WIN_H / 2 + col.steps / 2) * col.step;
	while (col.i < col.end)
	{
		pixel_put_tex(e, &col, rc, r);
		col.i++;
	}
}
