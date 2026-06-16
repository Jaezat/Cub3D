#include "main.h"

static void	set_cam_y(t_minimap *map, t_data *d)
{
	map->cam.y = (int)(d->py - (CAM_SIZE / 2));
	if (map->cam.y < 0)
		map->cam.y = 0;
	if (map->cam.y > d->map_h - CAM_SIZE)
	{
		if (d->map_h > CAM_SIZE)
			map->cam.y = d->map_h - CAM_SIZE;
		else
			map->cam.y = 0;
	}
	map->cam.limit_y = map->cam.y + CAM_SIZE;
}

static void	set_cam_x(t_minimap *map, t_data *d)
{
	map->cam.x = (int)(d->px - (CAM_SIZE / 2));
	if (map->cam.x < 0)
		map->cam.x = 0;
	if (map->cam.x > d->map_w - CAM_SIZE)
	{
		if (d->map_w > CAM_SIZE)
			map->cam.x = d->map_w - CAM_SIZE;
		else
			map->cam.x = 0;
	}
	map->cam.limit_x = map->cam.x + CAM_SIZE;
}

void	set_cam_values(t_env *env)
{
	set_cam_y(&env->minimap, env->data);
	set_cam_x(&env->minimap, env->data);
}
