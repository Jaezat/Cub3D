/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariacos <mariacos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 19:47:06 by mariacos          #+#    #+#             */
/*   Updated: 2026/08/06 19:47:07 by mariacos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	loop(void *param)
{
	t_env	*env;

	env = (t_env *)param;
	movement(env);
	put_background(env);
	mlx_put_image_to_window(env->umlx.mlx, env->umlx.win, env->umlx.img, 0, 0);
	usleep(1000000 / 60);
	return (0);
}
