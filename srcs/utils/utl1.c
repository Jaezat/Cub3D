#include "main.h"

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

void	ft_bzero(void *ref, size_t size)
{
	size_t	i;
	char	*mem;

	i = 0;
	mem = ref;
	while (i < size)
	{
		mem[i] = 0;
		i++;
	}
}

void	tf_memcpy(void *dest, void *src, size_t len)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = dest;
	s = src;
	if (src)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
}

void	ft_int_set(void *ref, size_t size, int value)
{
	size_t	i;
	int		*mem;

	i = 0;
	mem = ref;
	while (i < size)
	{
		mem[i] = value;
		i++;
	}
}
