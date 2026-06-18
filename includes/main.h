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

// internal library headers ///////////////////////////////////////////////////
# include "structs.h"                 // ← add this, must be first
// # include "parser/p_structs.h"
# include "windows/wdw_mlx_struct.h"
# include "parser/p_functions.h"
# include "parser/p_utils.h"
# include "minimap/mn_structs.h"
# include "windows/keys.h"
# include "minimap/mn_functions.h"

# define WIN_W 800
// # define TO_RATIO / 16 * 9
# define TO_RATIO / 1
# define WIN_H WIN_W TO_RATIO

# define M_PI 3.14159265358979323846
# define RAD M_PI / 180.0
# define ANG M_PI / 2

/*minimap*/
# define MAP_W 19
# define MAP_H 7 // number of tiles i want in my map


# define MINIMAP_SIZE 200
# define MINIMAP_TILE 10
# define MINIMAP_TILE_SIZE (MINIMAP_SIZE / CAM_SIZE)
# define CAM_SIZE 5
# define OFFSET (MINIMAP_TILE * 4)
# define MARGIN 0.01

# define K_LEFT 65361
# define K_UP 65362
# define K_RIGHT 65363
# define K_DOWN 65364
# define K_ESC 65307

# define K_A 97
# define K_W 119
# define K_D 100
# define K_S 115

# define MOV_INC 0.2
# define ANG_INC 2 // this is number of degrees per frame 
# define ANG_V ANG_INC * RAD

// keep this ? ////////////////////////////////////////////////////////////////
typedef int				(*t_clean)();

#endif
///////////////////////////////////////////////////////////////////////////////