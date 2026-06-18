#ifndef RAYCAST_H
# define RAYCAST_H

// put_background
// void	put_background(t_env *e);
// void	key_press(int keycode, void *param);
// // void	multi_ray(t_umlx *u);

// //puts
// void	get_addr(t_umlx *u);
// void	safe_pix_put(t_umlx *u, int byte, int color);
void	put_square(t_env *e, float hf, float wf, int color);
void	put_dot(t_env *e, float hf, float wf, int color);
// void	single_ray(t_umlx *u);

#endif