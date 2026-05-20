#include "cub3d.h"

void draw_minimap(t_map *map) // here we should be passing cub struct
{    
    map->wdw->map_y = 0;
    while (map->wdw->map_y < MAP_H)
    {
        map->wdw->map_x = 0;
        printf("map->wdw->map_y: %d\n", map->wdw->map_y);
        while(map->wdw->map_x < MAP_W)
        {
            map->wdw->c_map = map->prs->map[map->wdw->map_y][map->wdw->map_x];
            map->wdw->color = get_tile_color(map->prs->map[map->wdw->map_y][map->wdw->map_x]);
            map->wdw->px_y = 0;
            while (map->wdw->px_y < TILE_SIZE)
            {
                map->wdw->px_x = 0;
                while (map->wdw->px_x < TILE_SIZE)
                {
                    map->wdw->screen_x = (map->wdw->map_x * TILE_SIZE) + map->wdw->px_x;
                    map->wdw->screen_y = (map->wdw->map_y * TILE_SIZE) + map->wdw->px_y;
                    my_mlx_pixel_put(map->img_str, map->wdw->screen_x, map->wdw->screen_y, map->wdw->color);
                    map->wdw->px_x++;
                }
                map->wdw->px_y++;
            }
            map->wdw->map_x++;
        }
        map->wdw->map_y++;
    } 
}


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

    - PERO OJO -> esta funcion key_hook NO hace ninguno de esos calculos
    - key_hook es literalmente el mas simple de todos
    - su unico trabajo es decir "oye se presiono esta tecla" y nada mas
    - como lo hace? con flags -> variables booleanas (0 o 1) dentro del player
    - cada tecla tiene su propio flag:
        - W     -> keys.w     = 1
        - S     -> keys.s     = 1
        - A     -> keys.a     = 1  (ojo, A y D es strafe, no rotacion!)
        - D     -> keys.d     = 1  (strafe = moverse de lado sin girar la cabeza)
        - LEFT  -> keys.left  = 1  (esto si es rotacion)
        - RIGHT -> keys.right = 1  (esto si es rotacion)
    - eso es todo lo que hace key_hook, prende flags y ya

    - ahora necesito tambien un key_release
    - key_release es lo mismo pero al reves, apaga los flags cuando sueltas la tecla
    - sin key_release el jugador se queda moviendose para siempre
    - porque el flag queda en 1 y nadie lo apaga
    - entonces key_release es igual de importante que key_hook

    - entonces quien hace el movimiento real?
    - el game_loop -> ese corre cada frame y pregunta:
        - "esta keys.w en 1?"  -> si -> mover player hacia adelante usando dir
        - "esta keys.s en 1?"  -> si -> mover player hacia atras usando dir
        - "esta keys.a en 1?"  -> si -> strafe izquierda (perpendicular a dir)
        - "esta keys.d en 1?"  -> si -> strafe derecha (perpendicular a dir)
        - "esta keys.left en 1?"  -> si -> rotar dir y plane a la izquierda
        - "esta keys.right en 1?" -> si -> rotar dir y plane a la derecha
    - despues de mover/rotar -> redibuja todo -> y repite

    - el flujo completo entonces es:
        - jugador presiona W
        - OS le avisa a mlx "evento de tecla"
        - mlx llama a key_hook
        - key_hook prende keys.w = 1
        - game_loop en el proximo frame ve keys.w = 1
        - game_loop suma dir_x/dir_y a pos_x/pos_y multiplicado por move_speed
        - game_loop redibuja el mundo desde la nueva posicion
        - jugador suelta W
        - mlx llama a key_release
        - key_release apaga keys.w = 0
        - game_loop deja de mover al jugador
    no lo se rick tengo que ver como hago para convertir eso en codigo
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
    mlx_key_hook(map->mlx_wind, key_hook, &map);
     // mlx_hook para teclado
     // mlx_hook_loop para cerrar la ventana 
    mlx_loop(map->mlx);
    return (0);
} 