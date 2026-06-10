#ifndef MNP_FUNCTIONS_H
#define MNP_FUNCTIONS_H

void    draw_minimap(t_env *env);
void    my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
void    set_cam_values(t_env *env);
void    paint_pixel(t_env *env, int x, int y);
unsigned int    get_tile_color(char c);

#endif