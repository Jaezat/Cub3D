///////////////////////////////////////////////////////////////////////////////

// external library headers ///////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////
// compiled external headers //////////////////////////////////////////////////
#include "../mlx_linux/mlx.h"

// internal library headers ///////////////////////////////////////////////////
#include "parser/p_structs.h"
#include "wdw_mlx_struct.h"
#include "parser/p_functions.h"
#include "minimap.h"

// macros and defines /////////////////////////////////////////////////////////
// good for color codes, hexes, tables, weird return codes (-1, 0, 1)

// // this could be proportional to screen resolution
// // makes it slower on the iMacs
// # define WIN_W 1600
// // common widescreeen ratio
// # define TO_RATIO / 16 * 9
// // # define TO_RATIO / 1
// # define WIN_H WIN_W TO_RATIO
// // # define WIN_H 200

// mlx keycodes
# define K_LEFT 65361
# define K_UP 65362
# define K_RIGHT 65363
# define K_DOWN 65364
# define K_ESC 65307

# define K_A 97
# define K_W 119
# define K_D 100
# define K_S 115

// this could be proportional to screen resolution
// makes it slower on the iMacs
# define WIN_W 128 * 5
// common widescreeen ratio
# define TO_RATIO / 1
// # define TO_RATIO / 16 * 9
# define WIN_H WIN_W TO_RATIO
// # define WIN_H 200



// FILE1 //////////////////////////////////////////////////////////////////////

// FILE2 //////////////////////////////////////////////////////////////////////

// FILE3 //////////////////////////////////////////////////////////////////////

// STRUCTS //////////////////////////////////////////////////////////////////////




#endif

///////////////////////////////////////////////////////////////////////////////