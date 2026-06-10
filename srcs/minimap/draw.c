#include "main.h"

/* 
old version

static void draw_borders(t_env *game)
{
    int x;
    int y;
    int start;
    int end;

    set_cam_values(game.);
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
 */

/*  
before claude

static void draw_borders(t_env *env)
{
    int x;
    int y;
    int start;
    int end;

    set_cam_values(env->minimap);
    start = MINIMAP_TILE_SIZE - 2;
    end = MINIMAP_TILE_SIZE + CAM_SIZE * MINIMAP_TILE_SIZE + 2;
    y = start;
    while (y <= end)
    {
        x = start;
        while (x <= end)
        {
            my_mlx_pixel_put(&env->umlx.img_data, x, y, 0xFF33CC);
            x++;
        }
        y++;
    }
} 

static void draw_tiles(t_env *env)
{
    double y;
    double x;
    char m;

    set_cam_values(env->minimap);
    y = env->minimap.cam.y;
    while (y < env->minimap.cam.limit_y)
    {
        x = env->minimap.cam.x;
        while (x < env->minimap.cam.limit_x)
        {
            m = env->data->map[(int)y][(int)x];
            env->minimap->cam.c = get_tile_color(m);
            paint_pixel(env->minimap, (int)x, (int)y);
            x++;
        }
        y++;
    }
}

static void paint_player(t_env *env, double pp_x, double pp_y)
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
            my_mlx_pixel_put(&env->umlx.img_data, pp_x + px_x, pp_y + px_y, env->minimap.cam.c);
            px_x++;
        }
        px_y++;
    }
}

static void draw_player(t_env *env)
{
    double x;
    double y; 
    double player_px_x;
    double player_px_y;

    x = env->data->px - env->minimap.cam.x;
    y = env->data->py - env->minimap.cam.y;
    player_px_x = x * MINIMAP_TILE_SIZE;
    player_px_y = y * MINIMAP_TILE_SIZE;
    env->minimap.cam.c = 0xFF33CC;
    paint_player(env->minimap, player_px_x, player_px_y);
}

void draw_minimap(t_env *env)
{
    draw_borders(env);
    draw_tiles(env);
    draw_player(env);
    //move player?
}
 */

static void draw_borders(t_env *env)
{
	int	x;
	int	y;
	int	start;
	int	end;

	set_cam_values(env);
	start = MINIMAP_TILE_SIZE - 2;
	end = MINIMAP_TILE_SIZE + CAM_SIZE * MINIMAP_TILE_SIZE + 2;
	y = start;
	while (y <= end)
	{
		x = start;
		while (x <= end)
		{
			my_mlx_pixel_put(&env->umlx.img_data, x, y, 0xFF33CC);
			x++;
		}
		y++;
	}
}

static void draw_tiles(t_env *env)
{
	double	y;
	double	x;
	char	m;

	set_cam_values(env);
	y = env->minimap.cam.y;
	while (y < env->minimap.cam.limit_y)
	{
		x = env->minimap.cam.x;
		while (x < env->minimap.cam.limit_x)
		{
			m = env->data->map[(int)y][(int)x];
			env->minimap.cam.c = get_tile_color(m);
			paint_pixel(env, (int)x, (int)y);
			x++;
		}
		y++;
	}
}

static void paint_player(t_env *env, double pp_x, double pp_y)
{
	int	px_y;
	int	px_x;
	int	size;

	px_y = 0;
	size = 10;
	while (px_y < size)
	{
		px_x = 0;
		while (px_x < size)
		{
			my_mlx_pixel_put(&env->umlx.img_data, pp_x + px_x, pp_y + px_y, env->minimap.cam.c);
			px_x++;
		}
		px_y++;
	}
}

static void draw_player(t_env *env)
{
	double	x;
	double	y;
	double	player_px_x;
	double	player_px_y;

	x = env->data->px - env->minimap.cam.x;
	y = env->data->py - env->minimap.cam.y;
	player_px_x = x * MINIMAP_TILE_SIZE;
	player_px_y = y * MINIMAP_TILE_SIZE;
	env->minimap.cam.c = 0xFF33CC;
	paint_player(env, player_px_x, player_px_y);
}

void draw_minimap(t_env *env)
{
	draw_borders(env);
	draw_tiles(env);
	draw_player(env);
}



















