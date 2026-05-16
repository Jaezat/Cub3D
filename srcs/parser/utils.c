#include "main.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// TODO: doesnt free yet, just exits
void	exit_routine(t_parser *p)
{
	if (p->map_fd > -1)
		close(p->map_fd);
	exit(EXIT_FAILURE);
}

void	ft_puterr(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
}

void	safe_init(t_parser *p)
{
	p->arg_map_name = NULL;
	p->map_fd = -1;
}

// unit test
void	ft_bzero(char *mem, size_t size)
{
	size_t i = 0;
	while (i < size)
	{
		mem[i] = 0;
		i++;
	}
}
