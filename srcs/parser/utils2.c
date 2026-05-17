#include "main.h"

// needs unit testing
void	free_map(void *ref)
{
	char **map = *(char ***)ref;
	int i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
