#include "main.h"

// used to test gnl function in srcs/parser/gnl.c
void	pick_action(int keycode, t_umlx *u)
{
	(void)u;
	if (keycode == K_LEFT)
		printf("keycode: K_LEFT\n");
}

// mlx_clear_window(p->u->mlx, p->u->win);
// the cleaning routine can be rearranged to clean everything
// the mlx objects can be in one place
int	hook(int keycode, void *param)
{
	t_umlx	*u;

	u = param;
	if (keycode == K_ESC)
		exit_exec(u, 0);
	pick_action(keycode, u);
	return (1);
}

void	load_textures(t_umlx *u)
{
	t_data	*d;
	t_img	*img;
	int		i;
	char	**arr;

	d = u->d;
	arr = (char *[]){d->no, d->so, d->ea, d->we};
	i = 0;
	while (i < 4)
	{
		img = &d->imgs[i];
		img->ptr = mlx_xpm_file_to_image(u->mlx, arr[i], &img->w, &img->h);
		if (!img->ptr)
		{
			ft_puterr("Error\nFailed to load textures\n");
			exit_exec(u, 1);
		}
		i++;
	}
}

int	loop(void *param)
{
	t_umlx	*u;

	(void)param;
	u = param;
	get_addr(u);
	paint_put(u);
	mlx_put_image_to_window(u->mlx, u->win, u->img, 0, 0);
	// mlx_put_image_to_window(u->d->no, u->win, u->img, 0, 0);
	return (0);
}
