#include "main.h"

static void draw_borders(t_minimap *map)
{
    int x;
    int y;
    int start;
    int end;

    set_cam_values(map);
    start = MINIMAP_TILE_SIZE - 2;
    end = MINIMAP_TILE_SIZE + CAM_SIZE * MINIMAP_TILE_SIZE + 2;
    y = start;
    while (y <= end)
    {
        x = start;
        while (x <= end)
        {
            my_mlx_pixel_put(&map->ulx.img_data, x, y, 0xFF33CC);
            x++;
        }
        y++;
    }
} 

static void draw_tiles(t_minimap *map)
{
    double y;
    double x;
    char m;

    set_cam_values(map);
    y = map->cam.y;
    while (y < map->cam.limit_y)
    {
        x = map->cam.x;
        while (x < map->cam.limit_x)
        {
            m = map->d->map[(int)y][(int)x];
            map->cam.c = get_tile_color(m);
            paint_pixel(map, (int)x, (int)y);
            x++;
        }
        y++;
    }
}

static void paint_player(t_minimap *map, double pp_x, double pp_y)
{
    int px_y;
    int px_x;
    int size;

    px_y = 0;
    size = 10;
    while(px_y < size)
    {
        px_x = 0;
        while(px_x < size)
        {
            my_mlx_pixel_put(&map->ulx.img_data, pp_x + px_x, pp_y + px_y, map->cam.c);
            px_x++;
        }
        px_y++;
    }
}

static void draw_player(t_minimap *map)
{
    double x;
    double y;
    double player_px_x;
    double player_px_y;


    x = map->d->px - map->cam.x;
    y = map->d->py - map->cam.y;
    player_px_x = x * MINIMAP_TILE_SIZE;
    player_px_y = y * MINIMAP_TILE_SIZE;
    map->cam.c = 0xFF33CC;
    paint_player(map, player_px_x, player_px_y);
}

void draw_minimap(t_minimap *map)
{
    draw_borders(map);
    draw_tiles(map);
    draw_player(map);
    //move player?
}






























