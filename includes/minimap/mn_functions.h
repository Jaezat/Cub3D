#ifndef MNP_FUNCTIONS_H
#define MNP_FUNCTIONS_H


unsigned int get_tile_color(char c);
void draw_minimap(t_minimap *map); // here we should be passing cub struct
void my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
void set_cam_values(t_minimap *map);
void paint_pixel(t_minimap *map, int x, int y);

#endif