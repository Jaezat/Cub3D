// external library headers
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>

// internal library headers

// can be broken down into smaller headers

// macros and defines
// good for color codes, hexes, tables, weird return codes (-1, 0, 1)
#define RT_ERROR 1
#define RT_SUCCESS 0
#define STR_DIFF 1
#define STR_SAME 0

// // structures

typedef struct s_parser
{
}		t_parser;

typedef struct s_cubed
{
}		t_cubed;

// // prototypes
int		parsing(int argc, char **argv, t_parser *parser);

int		ft_strlen(char *str);
bool	is_cubed_extension(char *file);
int		parse_args(int argc, char **argv);
void	exit_routine(void *ref);
int		parsing(int argc, char **argv, t_parser *parser);

void	err_exit_msg(char *msg, char *variadic);
bool	is_cubed_ext(char *filename, char *extension);