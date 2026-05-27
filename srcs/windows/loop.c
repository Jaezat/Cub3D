#include "main.h"

// used to test gnl function in srcs/parser/gnl.c
void pick_action(int keycode)
{
	if (keycode == K_LEFT)
		printf("keycode: K_LEFT\n");
	if (keycode == K_A)
		printf("keycode: K_A\n");
	if (keycode == K_UP)
		printf("keycode: K_UP\n");
	if (keycode == K_W)
		printf("keycode: K_W\n");
	if (keycode == K_RIGHT)
		printf("keycode: K_RIGHT\n");
	if (keycode == K_D)
		printf("keycode: K_D\n");
	if (keycode == K_DOWN)
		printf("keycode: K_DOWN\n");
	if (keycode == K_S)
		printf("keycode: K_S\n");
}

// mlx_clear_window(p->u->mlx, p->u->win);
// the cleaning routine can be rearranged to clean everything
// the mlx objects can be in one place
int hook(int keycode, void *param)
{
	t_umlx *u;

	u = param;
	if (keycode == K_ESC)
		exit_exec(u, 0);
	return (1);
}

void load_textures(t_umlx *u)
{
	t_data *d;
	t_img *img;
	int i;
	char **arr;

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

int loop(void *param)
{
	t_game *env;

	env = (t_game *)param;
	paint_put(&env->u);
	draw_minimap(&env->mn);
	mlx_put_image_to_window(env->u.mlx, env->u.win, env->u.img, 0, 0);

	// i = -1;
	// while (++i < WIN_H)
	// {
	// 	j = -1;
	// 	while (++j < WIN_W)
	// 	{
	// 		// u->img
	// 	}
	// 	// usleep(10);
	// 	color += rand();
	// }
	// printf("%d\t", i);
	// mlx_put_image_to_window(u->mlx, u->win, u->img, 100, 100);
	// exit_exec(u, 0);
	return (0);
}
