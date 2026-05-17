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
void	exit_routine(t_parser *p, int exit_co)
{
	// add more variables as they are add in structure
	if (p->map_fd > -1)
		ft_safe_close(&p->map_fd);
	p->map_file = NULL; // because its on the stack
	if (p->map)
		free_map(&p->map);
	exit(exit_co);
}

void	ft_puterr(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
}

void	safe_init(t_parser *p)
{
	// add more variables as they are add in structure
	p->map_file = NULL;
	p->map = NULL;
	p->map_fd = -1;
}

// unit test
void	ft_bzero(void *ref, size_t size)
{
	size_t i = 0;
	char *mem = ref;
	while (i < size)
	{
		mem[i] = 0;
		i++;
	}
}
