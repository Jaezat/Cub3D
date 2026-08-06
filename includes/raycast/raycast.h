/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 19:43:06 by leschunc          #+#    #+#             */
/*   Updated: 2026/08/06 19:43:07 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

// raycast.c
int		wall_no(t_ray *r);
void	pixel_put_tex(t_env *e, t_col_draw *col, t_raycam *rc, t_ray *r);
void	find_hit(t_env *e, t_raycam *rc, t_ray *r);
void	set_jumps(t_env *e, t_raycam *rc, t_ray *r);

// puts.c
void	*get_addr_tex(t_img_data *img);
void	get_addr(t_umlx *u);
void	safe_pix_put(t_umlx *u, int byte, int color);
void	put_square(t_env *e, float hf, float wf, int c);
void	put_dot(t_env *e, float hf, float wf, int color);

// power.c
bool	it_power_two(int num);

// dda.c
void	shoot(t_env *e, t_raycam rc);
void	camera(t_env *e);
void	put_background(t_env *e);
void	exit_msg_exec(t_env *e, char *err_msg);
void	load_textures(t_env *e);

// col_draw.c
void	draw_col_conditions(t_env *e, t_raycam *rc, t_ray *r, t_col_draw *col);
void	draw_col(t_env *e, t_raycam *rc, t_ray *r);


#endif
