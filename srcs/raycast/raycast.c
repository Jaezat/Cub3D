#include "main.h"

void	put_background(t_env *e)
{
	int	*img;
	int	i;
	int	hr;
	int	wr;
	int	j;

	img = e->umlx.img_data.addr;
	ft_int_set(img, WIN_W * WIN_H, 0x808080);
	i = 0;
	hr = WIN_H / e->data->map_h;
	wr = WIN_W / e->data->map_w;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			if (e->data->map[i / hr][j / wr] == '1')
				img[i * WIN_W + j] = 0xffffff;
			j++;
		}
		i++;
	}
	put_square(e, e->data->py, e->data->px, 0xff0000);
}

// void	load_textures(t_umlx *u)
// {
// 	t_data	*d;
// 	t_img	*img;
// 	int		i;
// 	char	**arr;

// 	d = u->d;
// 	arr = (char *[]){d->no, d->so, d->ea, d->we};
// 	i = 0;
// 	while (i < 4)
// 	{
// 		img = &d->imgs[i];
// 		img->ptr = mlx_xpm_file_to_image(u->mlx, arr[i], &img->w, &img->h);
// 		if (!img->ptr)
// 		{
// 			ft_puterr("Error\nFailed to load textures\n");
// 			exit_exec(u, 1);
// 		}
// 		i++;
// 	}
// }