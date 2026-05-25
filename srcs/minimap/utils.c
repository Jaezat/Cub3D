#include "main.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst; 
    
	dst = data->addr + (y * data->line_s + x * (data->bpp / 8));
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