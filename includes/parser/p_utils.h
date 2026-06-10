///////////////////////////////////////////////////////////////////////////////
#ifndef P_UTILS_H
# define P_UTILS_H

// gnl ////////////////////////////////////////////////////////////////////////
size_t	line_len(char *str);
bool	has_line(char *str);
void	copier(char *dest, char *src, int len);
char	*joiner(char *line, char *buf);
char	*gnl(int fd);

// exit ///////////////////////////////////////////////////////////////////////
void	exit_parse(t_parser *p, int exit_co);
void    exit_exec(t_env *env, int exit_code);
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

// tester, remove later ///////////////////////////////////////////////////////
// void	test_rem(void);
// void	display_map(t_parser *p);
// void	print_t_parser(t_parser *p);
// void	print_t_data(t_data *d);
// void	disp_map_arr(t_parser *p);
#endif
///////////////////////////////////////////////////////////////////////////////