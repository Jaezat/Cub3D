#include "cub3d.h"

static void define_cam(t_map *map) // what i do here is that im assigning values and checking in case any of those points surpasses the map
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


void draw_minimap(t_map *map) // here we should be passing cub struct
{    
    define_cam(map);
    map->wdw->map_y = map->cam->top;
    while(map->wdw->map_y < map->cam->bot)
    {
        map->wdw->map_x  = map->cam->left;
        while(map->wdw->map_x < map->cam->right)
        {
            map->wdw->c_map = map->prs->map[map->wdw->map_y][map->wdw->map_x];
            map->wdw->color = get_tile_color(map->prs->map[map->wdw->map_y][map->wdw->map_x])
            map->wdw->px_y = 0;
            while(map->wdw->px_y < TILE_SIZE)
            {
                map->wdw->px_x = 0;
                while(map->wdw->px_x < TILE_SIZE)
                {
                    map->wdw->screen_x = (map->wdw->map_x * TILE_SIZE) + map->wdw->px_x;
                    map->wdw->screen_y = (map->wdw->map_y * TILE_SIZE) + map->wdw->px_y;
                    my_mlx_pixel_put(map->image_str, map->wdw->screen_x, map->wdw->screen_y, map->wdw->color);
                    map->wdw->px_x++;
                }
                map->wdw->px_y++;
            }
            map->wdw->map_x++;
        }
        map->wdw->map_y++;
    }
}
/*  */



void reset_window(t_img *data, int color)
{
    int x;
    int y;

    y = 0;
    while(y < WIN_H)
    {
        x = 0;
        while(x < WIN_W)
        {   
            my_mlx_pixel_put(data, x, y, color);
            x++;
        }
        y++;
    }
}

int render_each_frame(void *param)
{
   t_map *map = param;

    reset_window(map->img_str, 0x000000);  
    draw_minimap(map);
    // draw_raycast
    mlx_put_image_to_window(map->mlx, map->mlx_wind, map->img_str->img, 0, 0);
    return (0);
}

int	key_hook(int keycode, t_map *map)
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
	/* so basicamente aca:
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
}



int create_windows(t_map *map)
{
    map->mlx = mlx_init();
     if(!map->mlx)
         return (1);
    map->mlx_wind = mlx_new_window(map->mlx, WIN_W, WIN_H, "Cubed");
    map->img_str->img = mlx_new_image(map->mlx, WIN_W, WIN_H);
    map->img_str->addr = mlx_get_data_addr(
        map->img_str->img, 
         &(map->img_str->bits_per_pixel), 
         &(map->img_str->line_length), 
         &(map->img_str->endian));  
    mlx_loop_hook(map->mlx, render_each_frame,map);
    // mlx_key_hook(map->mlx_wind, key_hook, &map);
     // mlx_hook para teclado
     // mlx_hook_loop para cerrar la ventana 
    mlx_loop(map->mlx);
    return (0);
} 