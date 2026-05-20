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

// unit testing
int	ft_strncmp(char *s1, char *s2, size_t len)
{
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (*s2);
	if (!s2)
		return (*s1);
	while (s1[i] && i < len)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (false);
}

void	space_to_wall(void *ref, size_t size)
{
	size_t	i;
	char	*mem;

	i = 0;
	mem = ref;
	while (i < size)
	{
		if (mem[i] == ' ')
			mem[i] = 'X';
		i++;
	}
}
