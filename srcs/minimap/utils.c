#include "cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst; 
    
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

unsigned int get_tile_color(char c)
{
    if (c == '1')
        return (WALL);
    if (c == '0')
        return (FLOOR);
    if (c == 'E')
        return (PLAYER);
    return (EMPTY);
}