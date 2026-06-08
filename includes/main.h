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

# include "parser/p_structs.h"
# include "parser/p_functions.h"
# include "parser/p_utils.h"
# include "raycast/raycast.h"
# include "minimap.h"

# define WIN_W 800
// # define TO_RATIO / 16 * 9
# define TO_RATIO / 1
# define WIN_H WIN_W TO_RATIO

# define M_PI 3.14159265358979323846
# define RAD M_PI / 180.0

#define MOV_INC 0.1
#define ANG_INC 2

// keep this ? ////////////////////////////////////////////////////////////////
typedef int				(*t_clean)();

#endif
///////////////////////////////////////////////////////////////////////////////