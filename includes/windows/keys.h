/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariacos <mariacos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 19:59:59 by mariacos          #+#    #+#             */
/*   Updated: 2026/08/06 20:00:00 by mariacos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

int		press_key(int keycode, t_env *env);
int		release_key(int keycode, t_env *env);
int		close_windows(t_env *env);
void	hooks_keys(t_env *env);
void	movement(t_env *game);
bool	check_margin(t_data *data, float *new_y, float *new_x);
void	checking_position(t_data *data, float *new_y, float *new_x);

#endif