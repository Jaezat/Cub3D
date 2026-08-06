/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 19:43:12 by leschunc          #+#    #+#             */
/*   Updated: 2026/08/06 19:43:50 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///////////////////////////////////////////////////////////////////////////////
#ifndef MAIN_H
# define MAIN_H
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include "../mlx_linux/mlx.h"

# include "structs.h"
# include "parser/p_functions.h"
# include "parser/p_utils.h"
# include "windows/keys.h"
# include "raycast/raycast.h"

# define WIN_W 1600
# define WIN_H 900

# define M_PI 3.14159265358979323846
# define RAD 0.017453293
# define ANG 1.570796327

# define MARGIN 0.1

# define K_LEFT 65361
# define K_UP 65362
# define K_RIGHT 65363
# define K_DOWN 65364
# define K_ESC 65307

# define K_A 97
# define K_W 119
# define K_D 100
# define K_S 115

# define MOV_INC 0.1
# define ANG_INC 2
# define ANG_V 0.034906586

typedef int				(*t_clean)();

#endif