// external library headers
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// internal library headers

// can be broken down into smaller headers

// macros and defines
// good for color codes, hexes, tables, weird return codes (-1, 0, 1)
#define ERROR 1
#define SUCCESS 0
#define SAME 0

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
char	*is_cubed_extension(char *file);
int		parse_args(int argc, char **argv);
void	exit_routine(void *ref);
int		parsing(int argc, char **argv, t_parser *parser);

void	errmsg(char *msg);
