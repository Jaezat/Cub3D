///////////////////////////////////////////////////////////////////////////////
// external library headers ///////////////////////////////////////////////////
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// internal library headers ///////////////////////////////////////////////////
// can be broken down into smaller headers

// macros and defines /////////////////////////////////////////////////////////
// good for color codes, hexes, tables, weird return codes (-1, 0, 1)
// RT for return
#define RT_ERROR 1
#define RT_SUCCESS 0
// bool return for str diff
#define STR_DIFF 1
#define STR_SAME 0
// this is reasonably big for maps in the context of gnl
#define BUF_SIZE 32

// structures /////////////////////////////////////////////////////////////////
typedef struct s_parser
{
	int		map_fd;
	char	*arg_map_name;
}			t_parser;

typedef struct s_cubed
{
}			t_cubed;

// prototypes /////////////////////////////////////////////////////////////////
int			parsing(int argc, char **argv, t_parser *parser);

// init ///////////////////////////////////////////////////////////////////////
void		err_exit_msg(char *msg, char *arg, t_parser *p);
bool		is_cubed_ext(char *filename, char *extension);
bool		is_cubed_extension(char *file, t_parser *parser);
int			parse_args(int argc, char **argv, t_parser *parser);
int			parsing(int argc, char **argv, t_parser *parser);

// utils //////////////////////////////////////////////////////////////////////
int			ft_strlen(char *str);
void		exit_routine(t_parser *p);
void		safe_init(t_parser *p);
void		ft_puterr(char *str);
void		ft_bzero(char *mem, size_t size);

// gnl ////////////////////////////////////////////////////////////////////////
size_t		line_len(char *str);
bool		has_line(char *str);
void		str_copier(char *dest, char *src, int len);
char		*str_joiner(char *line, char *buf);
char		*gnl(int fd);

// assets /////////////////////////////////////////////////////////////////////
int			check_map(t_parser *p);

// tester, remove later ///////////////////////////////////////////////////////
void		test_rem(void);

///////////////////////////////////////////////////////////////////////////////