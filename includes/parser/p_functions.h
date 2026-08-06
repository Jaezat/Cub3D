/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_functions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leschunc <leschunc@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 19:42:03 by leschunc          #+#    #+#             */
/*   Updated: 2026/08/06 19:42:16 by leschunc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_FUNCTIONS_H
# define P_FUNCTIONS_H

// init ///////////////////////////////////////////////////////////////////////
bool	is_cubed_ext(char *filename, char *extension);
void	extension_check(char *file, char *ext, t_parser *p);
void	parse_args(int argc, char **argv, t_parser *parser);
void	get_player(t_data *d, int x, int y);
t_data	*parsing(int argc, char **argv);

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

// fill_h
void	pop(t_stack **old_top);
void	free_stack(t_stack *top);
t_stack	*push(t_parser *p, t_stack *old_top, int x, int y);
bool	is_space_at_limit(t_parser *p, t_stack ff, char **map);
bool	is_beyond_map_limit(t_parser *p, t_stack ff);

// fill ///////////////////////////////////////////////////////////////////////
void	flood_sched(t_parser *p, t_stack **top, t_stack ff);
void	flood_var_init(t_parser *p, t_flood_helper *h, int x, int y);
bool	flood_fill(t_parser *p, int x, int y, int pix);
void	start_flooding(t_parser *p);

// copy ///////////////////////////////////////////////////////////////////////
t_data	*pass_it_on(t_parser *parser);
void	remove_stray_lines(t_parser *parser, t_data *data);
void	get_floats(t_parser *p, t_data *d);

// mlx0 ////////////////////////////////////////////////////////////////////////
void	game(t_data *d);
void	put_background(t_env *e);
void	get_addr(t_umlx *u);

// mlx1 ////////////////////////////////////////////////////////////////////////
void	load_textures(t_env *e);
int		loop(void *param);

#endif