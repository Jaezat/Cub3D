#include "main.h"

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
	while (i < d->map_h)
	{
		d->map[i] = memdup(p->map[i], d->map_w);
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
	remove_stray_lines(p, d);
	d->map_w = p->exec_map_w - 1;
	d->ea = memdup(p->ea, ft_strlen(p->ea) + 1);
	d->we = memdup(p->we, ft_strlen(p->we) + 1);
	d->so = memdup(p->so, ft_strlen(p->so) + 1);
	d->no = memdup(p->no, ft_strlen(p->no) + 1);
	d->map = memdup(p->map, d->map_h * sizeof(char *));
	if (!d->ea || !d->we || !d->so || !d->no || !d->map)
		return (free_data(d), NULL);
	if (copy_matrix(p, d) == false)
		d = NULL;
	return (d);
}

void	remove_stray_lines(t_parser *p, t_data *d)
{
	int	i;

	i = 0;
	d->map_h = 0;
	while (p->map[i] && p->map[i][0])
	{
		if (p->map[i][0] != '\n')
			d->map_h++;
		i++;
	}
}

void	get_floats(t_parser *p, t_data *d)
{
	int		y;
	int		x;
	char	lt;

	y = 0;
	while (y < d->map_h)
	{
		x = 0;
		while (x < d->map_w)
		{
			lt = d->map[y][x];
			if (lt == 'N' || lt == 'E' || lt == 'S' || lt == 'W')
			{
				get_player(d, x, y);
				return ;
			}
			x++;
		}
		y++;
	}
	free_data(d);
	err_exit_msg("Couldn't find the player", 0, p);
}
