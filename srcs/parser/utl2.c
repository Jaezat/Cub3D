#include "main.h"

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
