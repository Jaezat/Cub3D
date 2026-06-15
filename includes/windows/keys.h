#ifndef KEYS_H
# define KEYS_H

int    press_key(int keycode, t_env *env);
int    release_key(int keycode, t_env *env);
int    close_windows(t_env *env);
void    hooks_keys(t_env *env);
void	movement(t_env *game);

#endif