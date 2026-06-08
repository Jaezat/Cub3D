#ifndef MINIMAP_H
#define MINIMAP_H

// minimap height and minimap width -> this is just a tester
#define MAP_W 19
#define MAP_H 7 // number of tiles i want in my map

// new minimap new me
#define MINIMAP_SIZE 150
#define MINIMAP_TILE 5
#define TILE_SIZE MINIMAP_SIZE / MINIMAP_TILE 

#define WALL   0xED094A  
#define FLOOR  0x00BBCA  
#define PLAYER 0x9E5167  
#define EMPTY  0x000000  

// this is harcoded atm, this should be a struct 
#define PLY_X   2
#define PLY_Y   5
#define RADIUS  1

unsigned int get_tile_color(char c);
// void draw_minimap(t_minimap *map); // here we should be passing cub struct
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
#endif