#include "main.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = parsing(argc, argv);
	game(data);
	if (data)
		free_data(data);
	return (0);
}
