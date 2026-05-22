#include "main.h"

// used to test gnl function in srcs/parser/gnl.c
void	pick_action(int keycode)
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

// mlx_clear_window(p->u->mlx, p->u->win);
// the cleaning routine can be rearranged to clean everything
// the mlx objects can be in one place
int	my_hook(int keycode, void *param)
{
	t_umlx	*u;

	u = param;
	pick_action(keycode);
	if (keycode == K_ESC)
		exit_exec(u, 0);
	return (1);
}

void	load_textures(t_umlx *u)
{
	t_data	*d;
	t_img	*img;
	int		i;

	d = u->d;
	i = 0;
	while (i < 4)
	{
		img = &d->imgs[i];
		img->ptr = mlx_xpm_file_to_image(u->mlx, d->no, &img->w, &img->h);
		if (!img->ptr)
		{
			ft_puterr("Error\nFailed to load textures\n");
			exit_exec(u, 1);
		}
		i++;
	}
}

void	render(t_data *d)
{
	t_umlx	u;

	ft_bzero(&u, sizeof(t_umlx));
	u.d = d;
	u.mlx = mlx_init();
	if (!u.mlx)
	{
		// exit_exec();
	};
	u.win = mlx_new_window(u.mlx, WIN_W, WIN_H, "Cub3d");
	if (!u.win)
	{
		// exit_exec();
	};
	// wrapper to load all textures
	load_textures(&u);
	// exit(0);
	mlx_put_image_to_window(u.mlx, u.win, d->imgs->ptr, 0, 0);
	mlx_key_hook(u.win, my_hook, &u);
	mlx_loop(u.mlx);
}
