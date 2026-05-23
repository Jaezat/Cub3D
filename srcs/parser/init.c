#include "main.h"

void	err_exit_msg(char *msg, char *arg, t_parser *p)
{
	ft_puterr("Error\n");
	ft_puterr(msg);
	if (arg)
		ft_puterr(arg);
	ft_puterr("\n");
	exit_parse(p, RT_ERROR);
}

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

// are the pointer arithmetics safe in all cases?
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

t_data	*parsing(int argc, char **argv)
{
	t_parser	parser;
	t_data		*data;

	safe_init(&parser);
	parse_args(argc, argv, &parser);
	check_map(&parser);
	data = NULL;
	data = pass_it_on(&parser);
	if (!data)
		exit_parse(&parser, RT_ERROR);
	exit_parse(&parser, RT_SUCCESS);
	return (data);
}
