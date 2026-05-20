#include "main.h"

void	tf_memcpy(void *dest, void *src, size_t len)
{
	size_t		i;
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

void	free_data(t_data *d)
{
	if (d->ea)
		free(d->ea);
	if (d->we)
		free(d->we);
	if (d->so)
		free(d->so);
	if (d->no)
		free(d->no);
	if (d->map)
	{
		free_matrix(d->map, d->map_h);
		d->map = NULL;
	}
	free(d);
}
