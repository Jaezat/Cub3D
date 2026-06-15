#include "main.h"

bool	is_cubed_ext(char *filename, char *extension)
{
	int	i;

	i = 0;
	while (filename[i])
	{
		if (filename[i] != extension[i])
			return (false);
		i++;
	}
	return (true);
}

// unit test
void	extension_check(char *file, char *ext, t_parser *p)
{
	int	ext_len;

	if (!*file)
		err_exit_msg("Empty filepath", 0, p);
	ext_len = ft_strlen(file);
	if (ext_len < 5)
		err_exit_msg("File path too short", 0, p);
	if (*(file + ext_len - 5) == '/')
		err_exit_msg("Name too short -> ", file + ext_len - 5, p);
	if (is_cubed_ext(file + ext_len - 4, ext) == false)
		err_exit_msg("Invalid extension -> ", file + ext_len - 4, p);
	p->map_file = file;
}

void	parse_args(int argc, char **argv, t_parser *p)
{
	if (argc > 2)
		err_exit_msg("Too many arguments", 0, p);
	if (argc < 2)
		err_exit_msg("Missing file path", 0, p);
	extension_check(argv[1], ".cub", p);
}

void	get_player(t_data *d, int x, int y)
{
	if (d->map[y][x] == 'N')
		d->dir = 270 * RAD;
	if (d->map[y][x] == 'E')
		d->dir = 0 * RAD;
	if (d->map[y][x] == 'S')
		d->dir = 90 * RAD;
	if (d->map[y][x] == 'W')
		d->dir = 180 * RAD;
	d->px = x + 0.5;
	d->py = y + 0.5;
	d->map[y][x] = '0';
}

t_data	*parsing(int argc, char **argv)
{
	t_parser	parser;
	t_data		*data;

	safe_init(&parser);
	parse_args(argc, argv, &parser);
	check_map(&parser);
	data = NULL;
	data = pass_it_on(&parser);
	get_floats(&parser, data);
	if (!data)
		exit_parse(&parser, RT_ERROR);
	exit_parse(&parser, RT_SUCCESS);
	return (data);
}
