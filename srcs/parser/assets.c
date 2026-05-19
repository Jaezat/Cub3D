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
		copier(buf, buf + line_len(buf), ft_strlen(buf));
	}
	return (0);
}

void	load_map_file(t_parser *p)
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

bool	is_element_count(t_parser *p, char *str)
{
	if (ft_strncmp(str, "NO ", 3) == SAME && p->no == NULL)
		p->no = str;
	else if (ft_strncmp(str, "SO ", 3) == SAME && p->so == NULL)
		p->so = str;
	else if (ft_strncmp(str, "WE ", 3) == SAME && p->we == NULL)
		p->we = str;
	else if (ft_strncmp(str, "EA ", 3) == SAME && p->ea == NULL)
		p->ea = str;
	else if (ft_strncmp(str, "F ", 2) == SAME && p->floor == NULL)
		p->floor = str;
	else if (ft_strncmp(str, "C ", 2) == SAME && p->ceiling == NULL)
		p->ceiling = str;
	else if (!(ft_strncmp(str, "\n", 1) == SAME))
		return (false);
	return (true);
}

// this is clunky, does it always work??
// second part checks if there is one element of each
// and the proceed to open them
// check .xpm ending similar to .cub
// count colors with commas and conver to int arr or single hexa 0xffffff
// err_exit_msg("Map requires one file per direction", 0, p);

void	check_map_elements(t_parser *p)
{
	int	i;

	i = 0;
	while (i < p->map_h)
	{
		if (is_element_count(p, p->map[i]) == false)
			break ;
		i++;
	}
	p->exec_map = p->map + i;
	p->exec_map_h = p->map_h - i;
	if (!p->ea || !p->no || !p->so || !p->we)
		err_exit_msg("Missing XPM identifier", 0, p);
	if (!p->floor || !p->ceiling)
		err_exit_msg("Missing floor or ceiling identifier", 0, p);
	trim_spaces_all(p);
}

// possible bug here or more memory being allocated than necessary
// char ** last element is null malloc + 1
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
	load_map_file(p);
	check_map_elements(p);
	print_ideal(p);
}
