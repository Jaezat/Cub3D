/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariacos <mariacos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 19:47:17 by mariacos          #+#    #+#             */
/*   Updated: 2026/08/06 19:47:18 by mariacos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	check_margin(t_data *data, float *new_y, float *new_x)
{
	char	**map;

	map = data->map;
	if (*new_y < 0 || *new_y >= data->map_h)
		return (false);
	if (*new_x < 0 || *new_x >= data->map_w)
		return (false);
	if (map[(int)*new_y][(int)*new_x] == '1')
		return (false);
	return (true);
}

bool	position_is_clear(t_data *data, float y, float x)
{
	float	left;
	float	right;
	float	top;
	float	bottom;

	left = x - MARGIN;
	right = x + MARGIN;
	top = y - MARGIN;
	bottom = y + MARGIN;
	return (check_margin(data, &top, &left) && check_margin(data, &top, &right)
		&& check_margin(data, &bottom, &left) && check_margin(data, &bottom,
			&right));
}

void	checking_position(t_data *data, float *new_y, float *new_x)
{
	if (position_is_clear(data, data->py, *new_x))
		data->px = *new_x;
	if (position_is_clear(data, *new_y, data->px))
		data->py = *new_y;
}
