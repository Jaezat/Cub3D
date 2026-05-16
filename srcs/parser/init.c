#include "main.h"

void	err_exit_msg(char *msg, char *arg)
{
	ft_puterr("Error\n");
	ft_puterr(msg);
	if (arg)
		ft_puterr(arg);
	ft_puterr("\n");
	exit_routine(NULL);
	exit(1);
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

// fd needs to get stored
bool	is_cubed_extension(char *file, t_parser *p)
{
	int	ext_len;

	if (!file || !*file)
		err_exit_msg("Empty filepath", 0);
	ext_len = ft_strlen(file);
	if (ext_len < 5)
		err_exit_msg("Too few characters for filepath", 0);
	if (*(file + ext_len - 5) == '/')
		err_exit_msg("Too few characters for map -> ", file + ext_len - 5);
	if (is_cubed_ext(file + ext_len - 4, ".cub") == false)
		err_exit_msg("Not a valid extension -> ", file + ext_len - 4);
	p->map_fd = open(file, O_RDONLY);
	if (p->map_fd == -1)
		err_exit_msg("Couldn't open file ", file);
	return (true);
}

int	parse_args(int argc, char **argv, t_parser *p)
{
	(void)argv;
	if (argc > 2)
		err_exit_msg("Too many arguments", 0);
	if (argc < 2)
		err_exit_msg("Missing argument: map filepath", 0);
	if (is_cubed_extension(argv[1], p))
		return (RT_SUCCESS);
	return (RT_ERROR);
}

int	parsing(int argc, char **argv, t_parser *p)
{
	(void)p;
	if (parse_args(argc, argv, p) == RT_ERROR)
		exit_routine(NULL);
	return (RT_SUCCESS);
}
