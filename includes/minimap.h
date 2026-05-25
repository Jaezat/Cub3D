#ifndef MINIMAP_H
#define MINIMAP_H

// minimap height and minimap width -> this is just a tester
#define MAP_W 19
#define MAP_H 7 // number of tiles i want in my map

// amount of pixels per tile 
#define TILE_SIZE 5
/* the amount of pixels we get here is tile_size * tile_size */

// colours

#define WALL   0xED094A  
#define FLOOR  0x00BBCA  
#define PLAYER 0x9E5167  
#define EMPTY  0x000000  

// this is harcoded atm, this should be a struct 
#define PLY_X   4
#define PLY_Y   4
#define RADIUS  2


typedef struct s_cubed t_cubed;

typedef struct s_camera
{
    int radius;
    float top;
    float bot;
    float left;
    float right;
}   t_cam;


typedef struct s_draw
{
    int map_y;
    int map_x;
    int px_y;
    int px_x;
    int screen_x;
    int screen_y;
    unsigned int color;
    char c_map;
}   t_draw;


typedef struct s_minimap
{
    t_draw      *wdw;
    t_cam       *cam;
    t_data      *d;
    int i;
    t_umlx      *ulx;
}   t_minimap; 




unsigned int get_tile_color(char c);
void    draw_minimap(t_minimap *map);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

#endif