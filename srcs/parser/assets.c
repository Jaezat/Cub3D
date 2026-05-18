#include "main.h"

// this needs unit testing
size_t	file_ln_count(t_parser *p)
{
	char	buf[BUF_SIZE + 1];
	int		r_size;
	size_t	lines;

	lines = 0;
	ft_bzero(buf, BUF_SIZE + 1);
	while (1)
	{
		if (!*buf)
		{
			r_size = read(p->map_fd, buf, BUF_SIZE);
			if (r_size == 0)
				return (++lines);
			if (r_size == -1)
				return (0);
			buf[r_size] = 0;
		}
		if (has_line(buf))
			lines++;
		str_copier(buf, buf + line_len(buf), ft_strlen(buf));
	}
	return (0);
}

void	load_map(t_parser *p)
{
	int	i;

	ft_safe_close(&p->map_fd);
	p->map_fd = open(p->map_file, O_RDONLY);
	if (p->map_fd == -1)
		err_exit_msg("Couldn't open file -> ", p->map_file, p);
	i = 0;
	while (i < p->map_h)
	{
		p->map[i] = gnl(p->map_fd);
		i++;
	}
	if (i < p->map_h)
		err_exit_msg("Map was not loaded completely", 0, p);
	ft_safe_close(&p->map_fd);
}

void	check_map(t_parser *p)
{
	p->map_fd = open(p->map_file, O_RDONLY);
	if (p->map_fd == -1)
		err_exit_msg("Couldn't open file ", p->map_file, p);
	p->map_h = file_ln_count(p);
	if (p->map_h < 3)
		err_exit_msg("Map doesn't meet minimum size", 0, p);
	p->map = malloc(sizeof(char *) * (p->map_h + 1));
	ft_bzero(p->map, sizeof(char *) * (p->map_h + 1));
	if (!p->map)
		err_exit_msg("Failed to allocate memory for map", 0, p);
	load_map(p);
	display_map(p);
}
