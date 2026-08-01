#include "main.h"

// void	splash(t_parser *p, int r, int c, char tag)
// {
// 	int	r_max;
// 	int	c_max;
// 	int	dot;

// 	r_max = p->exec_map_h;
// 	c_max = p->exec_map_w;
// 	if (r < 0 || c < 0 || r >= r_max || c >= c_max)
// 		return ;
// 	dot = p->map[r][c];
// 	if (dot == '1' || dot == tag)
// 		return ;
// 	if (dot == 'X' || dot == 0)
// 		err_exit_msg("Map is open", 0, p);
// 	p->map[r][c] = tag;
// 	splash(p, r + 1, c, tag);
// 	splash(p, r - 1, c, tag);
// 	splash(p, r, c - 1, tag);
// 	splash(p, r, c + 1, tag);
// }

void	check_borders(t_parser *p)
{
	int	i;

	i = 0;
	while (i < p->exec_map_h)
	{
		if (p->exec_map[i][0] != '1')
			err_exit_msg("There is a void on the map", 0, p);
		if (p->exec_map[i][p->exec_map_w - 2] != '1')
			err_exit_msg("There is a void on the map", 0, p);
		i++;
	}
	i = 0;
	while (i < p->exec_map_w - 1)
	{
		if (p->exec_map[0][i] != '1')
			err_exit_msg("There is a void on the map", 0, p);
		if (p->exec_map[p->exec_map_h - 1][i] != '1')
			err_exit_msg("There is a void on the map", 0, p);
		i++;
	}
}

void	start_flooding(t_parser *p)
{
	int	i;
	int	j;

	i = 0;
	while (i < p->exec_map_h && p->exec_map[i])
	{
		j = 0;
		while (j < p->exec_map_w)
		{
			if (i > 0 && p->map[i - 1][j] == 'X')
				err_exit_msg("There is a void on the map", 0, p);
			if (i < p->exec_map_h - 1 && p->exec_map[i + 1] && p->map[i
				+ 1][j] == 'X')
				err_exit_msg("There is a void on the map", 0, p);
			if (j > 0 && p->map[i][j - 1] == 'X')
				err_exit_msg("There is a void on the map", 0, p);
			if (j < p->exec_map_w - 1 && p->map[i][j + 1] == 'X')
				err_exit_msg("There is a void on the map", 0, p);
			j++;
		}
		i++;
	}
	check_borders(p);
}
