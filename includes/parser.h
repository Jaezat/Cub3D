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

// enum ///////////////////////////////////////////////////////////////////////


// structures /////////////////////////////////////////////////////////////////
typedef struct s_parser
{
	int		map_fd;
	char	*map_file;
	char	**map;
	int		map_h;
}			t_parser;

// prototypes /////////////////////////////////////////////////////////////////
int			parsing(int argc, char **argv, t_parser *parser);

// init ///////////////////////////////////////////////////////////////////////
void		err_exit_msg(char *msg, char *arg, t_parser *p);
bool		is_cubed_ext(char *filename, char *extension);
void		extension_check(char *file, t_parser *parser);
void		parse_args(int argc, char **argv, t_parser *parser);
int			parsing(int argc, char **argv, t_parser *parser);

// utils //////////////////////////////////////////////////////////////////////
int			ft_strlen(char *str);
void		exit_routine(t_parser *p, int exit_co);
void		safe_init(t_parser *p);
void		ft_puterr(char *str);
void		ft_bzero(void *mem, size_t size);

// utils2 //////////////////////////////////////////////////////////////////////
void		free_map(void *ref);
void		ft_safe_close(int *fd);

// gnl ////////////////////////////////////////////////////////////////////////
size_t		line_len(char *str);
bool		has_line(char *str);
void		str_copier(char *dest, char *src, int len);
char		*str_joiner(char *line, char *buf);
char		*gnl(int fd);

// assets /////////////////////////////////////////////////////////////////////
void		check_map(t_parser *p);
void		load_map(t_parser *p);
size_t		file_ln_count(t_parser *p);

// tester, remove later ///////////////////////////////////////////////////////
void		test_rem(void);
void		display_map(t_parser *p);

///////////////////////////////////////////////////////////////////////////////