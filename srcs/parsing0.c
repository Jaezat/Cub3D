#include "main.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*is_cubed_extension(char *file)
{
	int		i;
	int		ext_len;
	char	*filename;

	if (!file || !*file)
		return (NULL);
	ext_len = ft_strlen(file);
	if (ext_len < 5)
		printf("Error\n")

	i = 0;
	while (file[i])
	{
		if (file[i] == '/')
			filename = file + i;
		printf("filename [%s]\n", filename);
		i++;
	}
	return (NULL);
}

int	parse_args(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		// TODO: change this error message later
		printf("Error\nNot enough arguments\n");
		return (ERROR);
	}
	if (is_cubed_extension(argv[1]))
		return (SUCCESS);
	return (ERROR);
}

// TODO: doesnt free yet, just exits
void	exit_routine(void *ref)
{
	free(ref);
	exit(1);
}

int	parsing(int argc, char **argv, t_parser *parser)
{
	(void)parser;
	if (parse_args(argc, argv) == ERROR)
	{
		// TODO: this is not freeing anything yet
		exit_routine(NULL);
	}
	return (SUCCESS);
}

// void cleanups();



//////////////////////////////////////////////a.cub