#include "main.h"

// needs unit testing
void	free_map(void *ref)
{
	char	**map;
	int		i;

	map = *(char ***)ref;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_safe_close(int *fd)
{
	if (*fd != -1)
		close(*fd);
	*fd = -1;
}