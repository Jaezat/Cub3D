#ifndef MNP_STRUCTS_H
#define MNP_STRUCTS_H

#define MAP_W 19
#define MAP_H 7 // number of tiles i want in my map

// new minimap new me
#define MINIMAP_SIZE 200
#define MINIMAP_TILE 10
#define MINIMAP_TILE_SIZE (MINIMAP_SIZE / CAM_SIZE)
#define CAM_SIZE 5

#define WALL   0xFFFF00 
#define FLOOR  0x66CCFF  
#define PLAYER 0x6600CC 
#define EMPTY  0x000000  

typedef struct s_cubed t_cubed;

typedef struct s_camera
{
    double x; // coordenada x de donde empieza la camara en el mapa
    double y; // coordenada y de donde empieza la camara
    double limit_x;
    double limit_y;
    unsigned int c;
}   t_cam;

typedef struct s_minimap
{
    t_cam       cam;
    t_data      *d;
    int i;
    t_umlx      ulx;
}   t_minimap; 

typedef struct s_game
{
    t_umlx	u;
	t_minimap mn;
} t_game;


#endif 