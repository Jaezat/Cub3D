#include "main.h"

// used to test gnl function in srcs/parser/gnl.c
void	test_rem(void)
{
	int		fd;
	char	*line;

	fd = open("srcs/parser/gnl.c", O_RDONLY);
	while (1)
	{
		line = gnl(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	exit(0);
}