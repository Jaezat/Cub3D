#include "parser_structs.h"
#ifndef PARSER_FUNCTIONS_H
# define PARSER_FUNCTIONS_H

// init ///////////////////////////////////////////////////////////////////////
bool	is_cubed_ext(char *filename, char *extension);
void	extension_check(char *file, char *ext, t_parser *p);
void	parse_args(int argc, char **argv, t_parser *parser);
t_data	*parsing(int argc, char **argv);
//                                                                           //

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

// trimmer ////////////////////////////////////////////////////////////////////
void	trim_convert(t_parser *p);
void	trim_spaces(char *str);
void	check_color_amount(char *str, char **rgb, t_parser *p);
void	convert_colors(int floor, char **rgb, t_parser *p);
void	color_array_to_int(int floor, t_parser *p);

// flood //////////////////////////////////////////////////////////////////////
void	flood_init(t_parser *p);
void	alloc_fill_matrix(t_parser *p, char **map);
void	check_valid_chars(t_parser *p);
void	get_check_width(t_parser *p);
void	free_matrix(void *ref, int h);

// fill ///////////////////////////////////////////////////////////////////////
void	start_flooding(t_parser *p);
void	splash(t_parser *p, int r, int c, char tag);
t_data	*pass_it_on(t_parser *parser);

// mlx ////////////////////////////////////////////////////////////////////////
void	pick_action(int keycode);
void	exit_exec(t_umlx *u, int exit_code);
int		hook(int keycode, void *param);
void	load_textures(t_umlx *u);
void	game(t_data *d);

// exit ///////////////////////////////////////////////////////////////////////
void	exit_parse(t_parser *p, int exit_co);
void	exit_exec(t_umlx *u, int exit_code);
void	free_data(t_data *d);
void	free_map(void *ref);
void	err_exit_msg(char *msg, char *arg, t_parser *p);

// utl0 ///////////////////////////////////////////////////////////////////////
int		ft_strlen(char *str);
void	ft_puterr(char *str);
void	safe_init(t_parser *p);
void	ft_safe_close(int *fd);
int		ft_isdigit(int c);

// utl1 ///////////////////////////////////////////////////////////////////////
void	ft_bzero(void *mem, size_t size);
int		ft_strncmp(char *s1, char *s2, size_t len);
void	tf_memcpy(void *dest, void *src, size_t len);
void	space_to_wall(void *ref, size_t size);

// utl2 ///////////////////////////////////////////////////////////////////////

// tester, remove later ///////////////////////////////////////////////////////
// void	test_rem(void);
// void	display_map(t_parser *p);
// void	print_t_parser(t_parser *p);
// void	print_t_data(t_data *d);
// void	disp_map_arr(t_parser *p);
#endif

///////////////////////////////////////////////////////////////////////////////
