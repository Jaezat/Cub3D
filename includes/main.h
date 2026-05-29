///////////////////////////////////////////////////////////////////////////////
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <sys/time.h>
#define _USE_MATH_DEFINES

#ifndef MAIN_H
# define MAIN_H
#include "../mlx_linux/mlx.h"

#include "parser/p_structs.h"
#include "wdw_mlx_struct.h"
#include "parser/p_functions.h"
#include "parser/p_utils.h"
#include "minimap.h"

# define WIN_W 800
# define TO_RATIO / 4 * 3
// # define TO_RATIO / 1
# define WIN_H WIN_W TO_RATIO

# define K_LEFT 65361
# define K_UP 65362
# define K_RIGHT 65363
# define K_DOWN 65364
# define K_ESC 65307

# define K_A 97
# define K_W 119
# define K_D 100
# define K_S 115

#endif
///////////////////////////////////////////////////////////////////////////////