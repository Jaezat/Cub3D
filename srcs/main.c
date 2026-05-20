#include "main.h"

// window_test(&parser);
// execution between parsing and exit_routine
// check xpm integrity
int	main(int argc, char **argv)
{
	t_data	*data;

	data = parsing(argc, argv);
	print_t_data(data);
	if (data)
		free_data(data);
	return (0);
}
