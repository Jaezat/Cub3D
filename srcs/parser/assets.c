#include "main.h"

// this needs unit testing
size_t	file_lines(t_parser *p)
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

int	check_map(t_parser *p)
{
	int	n_lines;

	p->map_fd = open(p->arg_map_name, O_RDONLY);
	if (p->map_fd == -1)
		err_exit_msg("Couldn't open file ", p->arg_map_name, p);
	n_lines = file_lines(p);
	if (n_lines < 3)
		err_exit_msg("Map doesn't meet minimum size", 0, p);
	p->map = malloc(sizeof(char *) * (n_lines + 1));
	ft_bzero(p->map, sizeof(char *) * (n_lines + 1));
	if (!p->map)
		err_exit_msg("Failed to allocate memory for map", 0, p);
	// load_map(p);
	// printf("here\n");
	return (RT_SUCCESS);
}
