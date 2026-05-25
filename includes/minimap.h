#ifndef MINIMAP_H
#define MINIMAP_H

// full game window
#define WIN_W 1280
#define WIN_H 720

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


typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

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

typedef struct s_key
{
    double new_x;
    double new_y;
    double angle;
}   t_key;

typedef struct s_map
{
    void    *mlx;
    void    *mlx_wind;
    float     n_y;   //player row
    float     n_x;   // player vertical
    t_img   *img_str;
    t_parser *prs;
    t_draw *wdw;
    t_key  *key; 
    t_cam *cam;
}   t_map;

/* windows struct */
typedef struct s_win
{
    int win_width;
    int win_height;
}   t_win;

/* player struct */
typedef struct s_player_data
{
    float x;
    float y;
    float a;
    float vx; // [vector x] -> to know which direction the player is facing as a vector
    float vy; // idem but vector y instead;
}   t_player_data;

typedef struct s_minimap
{
    int win_width;
    int win_height;
}   t_minimap;


int create_windows(t_map *map);
int render_each_frame(void *param);
int struct_init(t_cubed **cub);
unsigned int get_tile_color(char c);
void    reset_window(t_img *data, int color);
void    draw_minimap(t_map *map);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

#endif