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
	while (i < p->exec_map_h)
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

void	*memdup(void *src, size_t size)
{
	char	*dest;

	dest = malloc(size);
	if (!dest)
		return (NULL);
	tf_memcpy(dest, src, size);
	return (dest);
}

bool	copy_matrix(t_parser *p, t_data *d)
{
	int	i;

	i = 0;
	while (i < p->exec_map_h)
	{
		d->map[i] = memdup(p->map[i], p->exec_map_w);
		if (!d->map[i])
			return (free_data(d), false);
		i++;
	}
	return (true);
}

t_data	*pass_it_on(t_parser *p)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	if (!d)
		return (NULL);
	ft_bzero(d, sizeof(t_data));
	d->ground = p->floor_hex;
	d->sky = p->ceiling_hex;
	d->map_h = p->exec_map_h;
	d->map_w = p->exec_map_w;
	d->ea = memdup(p->ea, ft_strlen(p->ea) + 1);
	d->we = memdup(p->we, ft_strlen(p->we) + 1);
	d->so = memdup(p->so, ft_strlen(p->so) + 1);
	d->no = memdup(p->no, ft_strlen(p->no) + 1);
	d->map = memdup(p->map, p->exec_map_h * sizeof(char *));
	if (!d->ea || !d->we || !d->so || !d->no || !d->map)
		return (free_data(d), NULL);
	if (copy_matrix(p, d) == false)
		d = NULL;
	return (d);
}
