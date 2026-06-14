#include "main.h"

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

static void	draw_player(t_env *env)
{
	double	player_px_x;
	double	player_px_y;
	int		tile_x;
	int		tile_y;

	tile_x = (int)env->data->px;
	tile_y = (int)env->data->py;
	player_px_x = (env->data->px - (int)env->minimap.cam.x)
		* MINIMAP_TILE_SIZE;
	player_px_y = (env->data->py - (int)env->minimap.cam.y)
		* MINIMAP_TILE_SIZE;
	player_px_x += OFFSET - (10 / 2);
	player_px_y += OFFSET - (10 / 2);
	env->minimap.cam.c = 0xFF33CC;
	paint_player(env, player_px_x, player_px_y);
}

void draw_minimap(t_env *env)
{
	printf("hi\n");
	draw_borders(env);
	draw_tiles(env);
	draw_player(env);
}
