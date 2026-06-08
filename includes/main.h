///////////////////////////////////////////////////////////////////////////////
#ifndef MAIN_H
# define MAIN_H
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <sys/time.h>

# define _USE_MATH_DEFINES

# include "../mlx_linux/mlx.h"
# include "parser/p_structs.h"
# include "wdw_mlx_struct.h"
# include "parser/p_functions.h"
# include "parser/p_utils.h"
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

#define MOV_INC 0.25
#define ANG_INC 6

// keep this ? ////////////////////////////////////////////////////////////////
typedef int				(*t_clean)();

#endif
///////////////////////////////////////////////////////////////////////////////