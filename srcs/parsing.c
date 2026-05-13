#include "main.h"

int parse_args(argc, argv)
{
	
}

int	parsing(int argc, char **argv)
{
	if (parse_args(argc, argv) == 1)
		exit_routine(NULL);
}

void	exit_routine(void *ref)
{
	// needs to receive the ref to free mem and exit
	// call a proper function to free the structures
	free(ref);
	exit(1);
}

// void cleanups();