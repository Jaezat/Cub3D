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
// 	if (dot == 'X' || dot == 0 || dot == ' ')
// 		err_exit_msg("Map is open", 0, p);
// 	p->map[r][c] = tag;
// 	splash(p, r + 1, c, tag);
// 	splash(p, r - 1, c, tag);
// 	splash(p, r, c - 1, tag);
// 	splash(p, r, c + 1, tag);
// }


void	splash(t_parser *p, int start_r, int start_c, char tag)
{
	int	r_max = p->exec_map_h;
	int	c_max = p->exec_map_w;
	int	dot;
	int	r;
	int	c;

	if (start_r < 0 || start_c < 0 || start_r >= r_max || start_c >= c_max)
		return ;

	// 1. Validamos que el mapa esté perfectamente cerrado
	r = 0;
	while (r < r_max)
	{
		c = 0;
		while (c < c_max)
		{
			dot = p->map[r][c];
			if (dot == 'X' || dot == 0 || dot == ' ')
			{
				if ((r > 0 && p->map[r - 1][c] == '0') ||
					(r < r_max - 1 && p->map[r + 1][c] == '0') ||
					(c > 0 && p->map[r][c - 1] == '0') ||
					(c < c_max - 1 && p->map[r][c + 1] == '0'))
				{
					err_exit_msg("Map is open", 0, p);
				}
			}
			c++;
		}
		r++;
	}

	// 2. ¡EL CAMBIO AQUÍ! 
	// En lugar de cambiar los '0' por el tag destructivo, mantén los '0' intactos
	// o asegúrate de cambiar solo lo necesario. Si tu motor gráfico necesita '0' 
	// para dibujar el suelo, no los cambies a 'X'.
	r = 0;
	while (r < r_max)
	{
		c = 0;
		while (c < c_max)
		{
			// Si tu motor espera '0' para pintar el suelo, déjalos como '0'.
			if (p->map[r][c] == '0')
				p->map[r][c] = '0'; // Mantener el suelo original
			c++;
		}
		r++;
	}
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
