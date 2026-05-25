#include "main.h"

// the idea here is to have minimal invocations in the main
// parsing exits within itself freeing the memory when necessary

int	main(int argc, char **argv)
{
	t_parser	parser;

	parsing(argc, argv, &parser);
	// call create_windows function 
	// cleaning routines its returning error as the program exits
	exit_routine(&parser, RT_SUCCESS);
	return (0);
}
