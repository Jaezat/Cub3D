/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 19:40:55 by leschunc          #+#    #+#             */
/*   Updated: 2026/08/06 19:40:56 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	destroy_textures(t_env *env, t_umlx *u)
{
	int			i;
	t_img_data	*img;
	t_data		*d;

	d = env->data;
	i = 0;
	while (i < 4)
	{
		img = d->imgs + i;
		if (img->img)
			mlx_destroy_image(u->mlx, img->img);
		i++;
	}
}
