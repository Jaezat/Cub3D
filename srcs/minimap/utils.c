#include "main.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = (((char *)data->addr) + (y * data->line_s + x * (data->bpp / 8)));
	*(unsigned int*)dst = color;
}

unsigned int get_tile_color(char c)
{
	if (c == '1')
		return (WALL);
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (FLOOR);
	return (0);
}

void paint_pixel(t_env *env, int x, int y)
{
	int	px_y;
	int	px_x;
	int	screen_x;
	int	screen_y;

	px_y = 0;
	while (px_y < MINIMAP_TILE_SIZE)
	{
		px_x = 0;
		while (px_x < MINIMAP_TILE_SIZE)
		{
			screen_x = (x - env->minimap.cam.x) * MINIMAP_TILE_SIZE + px_x + OFFSET;
			screen_y = (y - env->minimap.cam.y) * MINIMAP_TILE_SIZE + px_y + OFFSET;
			my_mlx_pixel_put(&env->umlx.img_data,
				screen_x, screen_y,
				env->minimap.cam.c);
			px_x++;
		}
		px_y++;
	}
}
