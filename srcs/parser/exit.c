#include "main.h"

// i dont know about this one // if (u->img) mlx_destroy_image(u->mlx, u->img);
void	exit_exec(t_umlx *u, int exit_code)
{
	int		i;
	t_img	*img;

	if (u->win)
		mlx_destroy_window(u->mlx, u->win);
	i = 0;
	while (i < 4)
	{
		img = u->d->imgs + i;
		if (img->ptr)
			mlx_destroy_image(u->mlx, img->ptr);
		i++;
	}
	if (u->mlx)
	{
		mlx_destroy_display(u->mlx);
		free(u->mlx);
	}
	if (u->d)
		free_data(u->d);
	exit(exit_code);
}

void	exit_parse(t_parser *p, int exit_co)
{
	ft_safe_close(&p->map_fd);
	if (p->map_tofree)
		free_map(&p->map_tofree);
	if (p->map)
	{
		free_matrix(p->map, p->exec_map_h);
		p->map = NULL;
	}
	if (exit_co == RT_ERROR)
		exit(exit_co);
}

void	free_map(void *ref)
{
	char	**map;
	int		i;

	map = *(char ***)ref;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_data(t_data *d)
{
	if (d->ea)
		free(d->ea);
	if (d->we)
		free(d->we);
	if (d->so)
		free(d->so);
	if (d->no)
		free(d->no);
	if (d->map)
	{
		free_matrix(d->map, d->map_h);
		d->map = NULL;
	}
	free(d);
}
