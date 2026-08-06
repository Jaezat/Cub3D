/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 19:40:48 by leschunc          #+#    #+#             */
/*   Updated: 2026/08/06 19:40:49 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	shoot(t_env *e, t_raycam rc)
{
	t_ray	r;

	r.map_x = (int)e->data->px;
	r.map_y = (int)e->data->py;
	r.hit = 0;
	if (rc.r_dir_x == 0)
		r.x_jump = INFINITY;
	else
		r.x_jump = fabs(1 / rc.r_dir_x);
	if (rc.r_dir_y == 0)
		r.y_jump = INFINITY;
	else
		r.y_jump = fabs(1 / rc.r_dir_y);
	set_jumps(e, &rc, &r);
	find_hit(e, &rc, &r);
}

void	camera(t_env *e)
{
	t_raycam	rc;

	rc.cam_x = -e->data->dir_y * 0.66;
	rc.cam_y = e->data->dir_x * 0.66;
	rc.x = 0;
	while (rc.x < WIN_W)
	{
		rc.col = 2 * rc.x / (float)WIN_W - 1;
		rc.r_dir_x = e->data->dir_x + rc.cam_x * rc.col;
		rc.r_dir_y = e->data->dir_y + rc.cam_y * rc.col;
		shoot(e, rc);
		rc.x++;
	}
}

void	put_background(t_env *e)
{
	int	*img;

	img = e->umlx.img_data.addr;
	ft_int_set(img, WIN_W * WIN_H / 2, e->data->sky);
	ft_int_set(img + WIN_W * WIN_H / 2, WIN_W * WIN_H / 2, e->data->ground);
	camera(e);
}

void	exit_msg_exec(t_env *e, char *err_msg)
{
	ft_puterr(err_msg);
	exit_exec(e, 1);
}

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
			exit_msg_exec(e, "Error\nFailed to load textures\n");
		if (img->w != img->h || img->w < 1)
			exit_msg_exec(e, "Error\nTextures need to be perfectly squared\n");
		if (!it_power_two(img->w))
			exit_msg_exec(e, "Error\nTextures need to be a power of two\n");
		if (!get_addr_tex(img))
			exit_msg_exec(e, "Error\nFailed to get texture addresses\n");
		i++;
	}
}
