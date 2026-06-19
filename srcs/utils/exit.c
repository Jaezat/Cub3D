#include "main.h"

// i dont know about this one // if (u->img) mlx_destroy_image(u->mlx, u->img);
// should aways have an error message even when mlx funcs fail??
void	exit_exec(t_env *env, int exit_code)
{
	int		i;
	t_umlx	*u;
	t_data	*d;
	t_img	*img;

	i = 0;
	d = env->data;
	u = &env->umlx;
	if (u->img)
		mlx_destroy_image(u->mlx, u->img);
	if (u->win)
		i = 0;
	while (i < 4)
	{
		img = d->imgs + i;
		if (img->ptr)
			mlx_destroy_image(u->mlx, img->ptr);
		i++;
	}
	mlx_destroy_window(u->mlx, u->win);
	if (u->mlx)
	{
		mlx_destroy_display(u->mlx);
		free(u->mlx);
	}
	if (env->data)
		free_data(env->data);
	exit(exit_code);
}

void	exit_parse(t_parser *p, int exit_co)
{
	ft_safe_close(&p->map_fd);
	if (p->map_head)
		free_map(&p->map_head);
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

// changed this so need to make sure that it doesnt break
void	free_data(t_data *d)
{
	// if (d->ea)
	// 	free(d->ea);
	// if (d->we)
	// 	free(d->we);
	// if (d->so)
	// 	free(d->so);
	// if (d->no)
	// 	free(d->no);
	// if (d->map)
	// {
	// 	free_matrix(d->map, d->map_h);
	// 	d->map = NULL;
	// }
	// free(d);
}

void	err_exit_msg(char *msg, char *arg, t_parser *p)
{
	ft_puterr("Error\n");
	ft_puterr(msg);
	if (arg)
		ft_puterr(arg);
	ft_puterr("\n");
	exit_parse(p, RT_ERROR);
}
