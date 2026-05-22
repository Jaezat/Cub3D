#include "main.h"

// execution between parsing and exit_routine
int	main(int argc, char **argv)
{
	t_data	*data;

	data = parsing(argc, argv);
	render(data);
	if (data)
		free_data(data);
	return (0);
}
