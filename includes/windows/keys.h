#ifndef KEYS_H
# define KEYS_H

void    press_key(int keycode, t_env *env);
void    release_key(int keycode, t_env *env);
void    close_windows(t_env *env);
void    hooks_keys(t_env *env);

#endif