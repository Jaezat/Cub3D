#include "main.h"

// the idea here is to have minimal clutter in the main
// parsing exits within itself freeing the memory when necessary
// window_test(&parser);
// execution between parsing and exit_routine
// maybe needs to be integrated with exec exit routine
int	main(int argc, char **argv)
{
	t_parser	parser;

	parsing(argc, argv, &parser);
	exit_routine(&parser, RT_SUCCESS);
	return (0);
}
