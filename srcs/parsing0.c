#include "main.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

bool	is_cubed_extension(char *file)
{
	int	ext_len;
	int	fd;

	if (!file || !*file)
		err_exit_msg("Empty filepath", 0);
	ext_len = ft_strlen(file);
	if (ext_len < 5)
		err_exit_msg("Too few characters for filepath", 0);
	if (*(file + ext_len - 5) == '/')
		err_exit_msg("Too few characters for map -->", file + ext_len - 5);
	if (is_cubed_ext(file + ext_len - 4, ".cub") == false)
		err_exit_msg("Not a valid extension -->", file + ext_len - 4);
	// this needs to get stored
	fd = open(file, O_RDONLY);
	if (fd == -1)
		err_exit_msg("Couldn't open file ", file);
	return (true);
}

int	parse_args(int argc, char **argv)
{
	(void)argv;
	if (argc > 2)
		err_exit_msg("Too many arguments", 0);
	if (argc < 2)
		err_exit_msg("Missing argument: map filepath", 0);
	if (is_cubed_extension(argv[1]))
		return (RT_SUCCESS);
	return (RT_ERROR);
}

// TODO: doesnt free yet, just exits
void	exit_routine(void *ref)
{
	free(ref);
	exit(EXIT_FAILURE);
}

int	parsing(int argc, char **argv, t_parser *parser)
{
	(void)parser;
	if (parse_args(argc, argv) == RT_ERROR)
	{
		// printf("here");
		// TODO: this is not freeing anything yet
		exit_routine(NULL);
	}
	return (RT_SUCCESS);
}
