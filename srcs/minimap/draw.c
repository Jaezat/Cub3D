#include "main.h"

static void define_cam(t_minimap *map) // what i do here is that im assigning values and checking in case any of those points surpasses the map
{
    map->cam->top = PLY_Y - RADIUS;
	if (map->cam->top < 0)
		map->cam->top = 0;
    map->cam->bot = PLY_Y + RADIUS;
	if (map->cam->top > MAP_H)
		map->cam->top = MAP_H;
    map->cam->left = PLY_X - RADIUS;
	if (map->cam->left < 0)
		map->cam->left = 0;
    map->cam->right = PLY_X + RADIUS;
	if (map->cam->left > MAP_W)
		map->cam->left = MAP_W;
}


void draw_minimap(t_minimap *map) // here we should be passing cub struct
{    
    define_cam(map);
    map->wdw->map_y = map->cam->top;
    while(map->wdw->map_y < map->cam->bot)
    {
        map->wdw->map_x  = map->cam->left;
        while(map->wdw->map_x < map->cam->right)
        {
            map->wdw->c_map = map->d->map[map->wdw->map_y][map->wdw->map_x];
            map->wdw->color = get_tile_color(map->d->map[map->wdw->map_y][map->wdw->map_x]);
            map->wdw->px_y = 0;
            while(map->wdw->px_y < TILE_SIZE)
            {
                map->wdw->px_x = 0;
                while(map->wdw->px_x < TILE_SIZE)
                {
                    map->wdw->screen_x = (map->wdw->map_x * TILE_SIZE) + map->wdw->px_x;
                    map->wdw->screen_y = (map->wdw->map_y * TILE_SIZE) + map->wdw->px_y;
                    my_mlx_pixel_put(&map->ulx->img_data, map->wdw->screen_x, map->wdw->screen_y, map->wdw->color);
                    map->wdw->px_x++;
                }
                map->wdw->px_y++;
            }
            map->wdw->map_x++;
        }
        map->wdw->map_y++;
    }
} 

/* int	key_hook(int keycode, t_minimap *map)
{
    if (keycode == K_ESC)
	{
		// mlx_clear_window(p->u->mlx, p->u->win);
		mlx_destroy_image(p->u->mlx, p->u->img);
		mlx_destroy_window(p->u->mlx, p->u->win);
		mlx_destroy_display(p->u->mlx);
		free(p->u->mlx);
		exit_routine(p, 0);
	}
	 so basicamente aca:
    - 65307 -> ESC
    - Ok so en esta parte voy a estar necesitando varias cosas:
        - For movement (WASD):
            - update on where the player is (pos_x, pos_y)
            - which way to move forward (dir_x, dir_y)
            - how fast do i move? a var like move_speed
        - For rotation (left & right):
            - the exact location of player (dir_x, dir_y) in order to rotate
            - camera plane (it basically defines how wide my FOV is)
                - narrow FOV -> zoomed in
                - wider FOV -> zoomed out
            - se llama plane_x / plane_y, no fov_x/fov_y
                - porque no es solo el angulo de vision
                - es literalmente el plano de la camara en el mundo
                - y siempre tiene que estar perpendicular a dir
                - si dir rota, plane rota con el, siempre juntos
            - how fast do i turn? a var like rot_speed

    */



