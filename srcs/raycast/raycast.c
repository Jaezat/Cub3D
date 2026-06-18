#include "main.h"

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
