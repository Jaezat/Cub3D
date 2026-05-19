#include "parser_structs.h"

// prototypes /////////////////////////////////////////////////////////////////
int		parsing(int argc, char **argv, t_parser *parser);

// init ///////////////////////////////////////////////////////////////////////
void	err_exit_msg(char *msg, char *arg, t_parser *p);
bool	is_cubed_ext(char *filename, char *extension);
void	extension_check(char *file, char *ext, t_parser *p);
void	parse_args(int argc, char **argv, t_parser *parser);
int		parsing(int argc, char **argv, t_parser *parser);

// utils //////////////////////////////////////////////////////////////////////
int		ft_strlen(char *str);
void	exit_routine(t_parser *p, int exit_co);
void	safe_init(t_parser *p);
void	ft_puterr(char *str);
void	ft_bzero(void *mem, size_t size);

// utils2 //////////////////////////////////////////////////////////////////////
void	free_map(void *ref);
void	ft_safe_close(int *fd);
int		ft_strncmp(char *s1, char *s2, size_t len);
int		ft_isdigit(int c);

// gnl ////////////////////////////////////////////////////////////////////////
size_t	line_len(char *str);
bool	has_line(char *str);
void	copier(char *dest, char *src, int len);
char	*joiner(char *line, char *buf);
char	*gnl(int fd);

// assets /////////////////////////////////////////////////////////////////////
void	check_map(t_parser *p);
void	load_map_file(t_parser *p);
size_t	file_ln_count(t_parser *p);
void	check_map(t_parser *p);
bool	is_element_count(t_parser *p, char *str);

// assets2 ////////////////////////////////////////////////////////////////////
void	trim_spaces_all(t_parser *p);
void	trim_spaces(char *str);
void	check_color_amount(char *str, char **rgb, t_parser *p);
void	convert_colors(int floor, char **rgb, t_parser *p);
void	color_array_to_int(int floor, t_parser *p);

// tester, remove later ///////////////////////////////////////////////////////
void	test_rem(void);
void	display_map(t_parser *p);
// void	window_test(t_parser *p);
void	print_ideal(t_parser *p);

///////////////////////////////////////////////////////////////////////////////
