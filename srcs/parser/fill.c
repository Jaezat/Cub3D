#include "main.h"

void	splash(t_parser *p, int r, int c, char tag)
{
	int	r_max;
	int	c_max;
	int	dot;

	r_max = p->exec_map_h;
	c_max = p->exec_map_w;
	if (r < 0 || c < 0 || r >= r_max || c >= c_max)
		return ;
	dot = p->map[r][c];
	if (dot == '1' || dot == tag)
		return ;
	if (dot == 'X' || dot == 0)
		err_exit_msg("Map is open", 0, p);
	p->map[r][c] = tag;
	splash(p, r + 1, c, tag);
	splash(p, r - 1, c, tag);
	splash(p, r, c - 1, tag);
	splash(p, r, c + 1, tag);
}

void	start_flooding(t_parser *p)
{
	int		i;
	int		j;
	char	c;
	char	dir;

	i = 0;
	while (i < p->exec_map_h && p->exec_map[i])
	{
		j = 0;
		while (j < p->exec_map_w)
		{
			c = p->map[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				dir = p->map[i][j];
				splash(p, i, j, 'F');
				splash(p, i, j, '0');
				p->map[i][j] = dir;
			}
			j++;
		}
		i++;
	}
}
