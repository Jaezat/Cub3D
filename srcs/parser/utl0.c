#include "main.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_puterr(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
}

void	safe_init(t_parser *p)
{
	ft_bzero(p, sizeof(t_parser));
	p->map_fd = -1;
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
