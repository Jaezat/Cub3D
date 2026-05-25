#include "main.h"

// execution between parsing and exit_parse
int	main(int argc, char **argv)
{
	t_data	*data;

	data = parsing(argc, argv);
	
	game(data);
	if (data)
		free_data(data);
	return (0);
}
