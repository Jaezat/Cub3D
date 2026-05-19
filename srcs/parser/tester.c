#include "main.h"

// used to test gnl function in srcs/parser/gnl.c
void	test_rem(void)
{
	int		fd;
	char	*line;

	fd = open("srcs/parser/gnl.c", O_RDONLY);
	while (1)
	{
		line = gnl(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	exit(0);
}

// used to test whether the map was loaded successfully from file to mem
void	display_map(t_parser *p)
{
	int	i;

	i = 0;
	while (i < p->exec_map_h)
	{
		printf("%s", p->exec_map[i]);
		i++;
	}
}

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

// mlx_clear_window(p->u->mlx, p->u->win);
// the cleaning routine can be rearranged to clean everything
// the mlx objects can be in one place
// int	my_hook(int keycode, void *param)
// {
// 	t_parser	*p;

// 	p = param;
// 	pick_action(keycode);
// 	if (keycode == K_ESC)
// 	{
// 		mlx_destroy_image(p->u->mlx, p->u->img);
// 		mlx_destroy_window(p->u->mlx, p->u->win);
// 		mlx_destroy_display(p->u->mlx);
// 		free(p->u->mlx);
// 		exit_routine(p, 0);
// 	}
// 	return (1);
// }

// void	window_test(t_parser *p)
// {
// 	t_umlx	u;
// 	int		h;
// 	int		w;

// 	h = 0;
// 	w = 0;
// 	p->u = &u;
// 	u.mlx = mlx_init();
// 	u.win = mlx_new_window(u.mlx, WIN_W, WIN_H, "test");
// 	p->u->img = mlx_xpm_file_to_image(p->u->mlx, "assets/textures/lavender.xpm",
// 			&w, &h);
// 	mlx_put_image_to_window(p->u->mlx, p->u->win, p->u->img, 0, 0);
// 	mlx_key_hook(u.win, my_hook, p);
// 	mlx_loop(u.mlx);
// }

void	print_ideal(t_parser *p)
{
	int	i;

	printf("%s\n", p->no);
	printf("%s\n", p->so);
	printf("%s\n", p->we);
	printf("%s\n", p->ea);
	printf("%s\n", p->floor);
	printf("%s\n", p->ceiling);
	i = 0;
	while (p->exec_map[i])
	{
		printf("%s", p->exec_map[i]);
		i++;
	}
	printf("\n");
}
