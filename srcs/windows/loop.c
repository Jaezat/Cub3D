#include "main.h"

void	pick_action(int keycode, t_umlx *u)
{
	(void)u;
	if (keycode == K_LEFT)
		printf("keycode: K_LEFT\n");
}

int	hook(int keycode, void *param)
{
	t_umlx	*u;

	u = param;
	if (keycode == K_ESC)
		exit_exec(u, 0);
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

// draw_minimap(&env->mn);
int	loop(void *param)
{
	t_game	*env;

	env = (t_game *)param;
	raycast(&env->u);
	// minimap
	mlx_put_image_to_window(env->u.mlx, env->u.win, env->u.img, 0, 0);
	usleep(1000000 / 60);
	return (0);
}
