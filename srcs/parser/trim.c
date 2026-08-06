/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 19:37:42 by leschunc          #+#    #+#             */
/*   Updated: 2026/08/06 19:37:43 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	trim_spaces(char *str)
{
	int	start;
	int	end;

	start = 0;
	while (str[start] && str[start] != ' ')
		start++;
	start++;
	while (str[start] && str[start] == ' ')
		start++;
	copier(str, str + start, ft_strlen(str + start));
	end = ft_strlen(str) - 1;
	if (str[end] == '\n')
		end--;
	while (end >= 0 && str[end] == ' ')
	{
		end--;
	}
	str[end + 1] = 0;
}

void	check_color_amount(char *str, char **rgb, t_parser *p)
{
	int		n_colors;
	bool	in_space;
	int		i;
	int		commas;

	commas = 0;
	n_colors = 0;
	in_space = true;
	i = -1;
	while (str[++i])
	{
		if (str[i] == ',')
			commas++;
		if (!ft_isdigit(str[i]) && str[i] != ',' && str[i] != ' ')
			break ;
		if (ft_isdigit(str[i]) && in_space == true)
		{
			in_space = false;
			rgb[n_colors++] = str + i;
		}
		else if (!ft_isdigit(str[i]) && in_space == false)
			in_space = true;
	}
	if (n_colors != 3 || commas != 2)
		err_exit_msg("Three colors required between commas", 0, p);
}

void	convert_colors(int floor, char **rgb, t_parser *p)
{
	int	color;
	int	*hex;
	int	i;

	hex = p->hex_c;
	if (floor == 0)
		hex = p->hex_f;
	color = 0;
	while (color < 3)
	{
		i = 0;
		while (rgb[color][i] && ft_isdigit(rgb[color][i]))
		{
			hex[color] *= 10;
			hex[color] += rgb[color][i] - '0';
			i++;
			if (hex[color] > 255)
				err_exit_msg("Color range must be 0 - 255", 0, p);
		}
		color++;
	}
}

void	color_array_to_int(int floor, t_parser *p)
{
	int				color_i;
	int				*hex;
	unsigned int	tmp;

	tmp = 0;
	hex = p->hex_c;
	if (floor == 0)
		hex = p->hex_f;
	color_i = 0;
	while (color_i < 3)
	{
		tmp <<= 8;
		tmp += (hex[color_i]);
		color_i++;
	}
	if (floor == 0)
		p->floor_hex = tmp;
	else
		p->ceiling_hex = tmp;
}

void	trim_convert(t_parser *p)
{
	char	**arr;
	int		i;
	char	***rgb_arr;

	rgb_arr = (char **[]){p->rgb_f, p->rgb_c};
	arr = (char *[]){p->ea, p->no, p->so, p->we};
	i = 0;
	while (i < 4)
	{
		trim_spaces(arr[i]);
		extension_check(arr[i], ".xpm", p);
		i++;
	}
	arr = (char *[]){p->floor, p->ceiling};
	i = 0;
	while (i < 2)
	{
		trim_spaces(arr[i]);
		check_color_amount(arr[i], rgb_arr[i], p);
		convert_colors(i, rgb_arr[i], p);
		color_array_to_int(i, p);
		i++;
	}
}
