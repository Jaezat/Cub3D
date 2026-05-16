#include "main.h"

// the idea here is to have minimal invocations in the main
// parsing exits within itself freeing the memory when necessary
int	main(int argc, char **argv)
{
	t_parser	parser;

	parsing(argc, argv, &parser);
	return (0);
}

// @jaz you're free to remove this if it clutters
// used to test gnl function in srcs/parser/gnl.c
// void	test(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("srcs/parser/gnl.c", O_RDONLY);
// 	while (1)
// 	{
// 		line = gnl(fd);
// 		if (!line)
// 			break ;
// 		printf("%s", line);
// 		free(line);
// 	}
// 	exit(0);
// }