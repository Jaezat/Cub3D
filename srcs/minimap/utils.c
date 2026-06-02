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

void set_cam_values(t_minimap *map)
{
    map->cam.x = map->d->px - (CAM_SIZE / 2);
    if (map->cam.x < 0)
        map->cam.x = 0;
    if (map->cam.x > map->d->map_w - CAM_SIZE)
        map->cam.x = map->d->map_w - CAM_SIZE;
    map->cam.y = map->d->py - (CAM_SIZE / 2);
    if(map->cam.y < 0)
        map->cam.y = 0;
    if (map->cam.y > map->d->map_h - CAM_SIZE)
        map->cam.y = map->d->map_h - CAM_SIZE;
    map->cam.limit_x = map->cam.x + CAM_SIZE;
    map->cam.limit_y = map->cam.y + CAM_SIZE;
}

void paint_pixel(t_minimap *map, int x, int y)
{
    int px_y;
    int px_x;
    int screen_x;
    int screen_y;
    int offset;

    offset = MINIMAP_TILE * 4;
    px_y = 0;
    while(px_y < MINIMAP_TILE_SIZE)
    {
        px_x = 0;
        while(px_x < MINIMAP_TILE_SIZE)
        {
            screen_x = (x - (int)map->cam.x) * MINIMAP_TILE_SIZE + px_x + offset;
            screen_y = (y - (int)map->cam.y) * MINIMAP_TILE_SIZE + px_y + offset;
            my_mlx_pixel_put(&map->ulx.img_data, screen_x, screen_y, map->cam.c);
            px_x++;
        }
        px_y++;
    }
}