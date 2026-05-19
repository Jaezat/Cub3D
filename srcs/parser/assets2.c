#include "main.h"

// this guy needs some SERIOUS UNIT TESTING
// it runs the chars, then one space if it got here
// it then moves the argument after the id to the start of str
// it goes to the end char if its a newline it moves back one
// it then moves back to ignore all ending spaces and places '\0'
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
		err_exit_msg("Needs three colors between commas", 0, p);
}

void	convert_colors(int floor, char **rgb, t_parser *p)
{
	int	color;
	int	*hex;
	int	i;

	color = 0;
	hex = p->hex_c;
	if (floor)
		hex = p->hex_f;
	while (color < 2)
	{
		// printf(">%s\n", rgb[color]);
		i = 0;
		while (ft_isdigit(rgb[color][i]) && i < 3)
		{
			// printf(">>>%c\n", rgb[color][i]);
			hex[color] *= 10;
			hex[color] += rgb[color][i] - '0';
			i++;
		}
		if (hex[color] > 255)
			err_exit_msg("Color range must be 0 - 255", 0, p);
		color++;
	}
}

void	trim_spaces_all(t_parser *p)
{
	char	**arr;
	int		i;
	char	**rgb_arr[2] = {p->rgb_f, p->rgb_c};

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
		i++;
	}
}
