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
// add more variables as they are add in structure
// map_file is on the stack
// p->map_file = NULL;
void	exit_routine(t_parser *p, int exit_co)
{
	if (!p)
		exit(exit_co);
	ft_safe_close(&p->map_fd);
	if (p->map)
		free_map(&p->map);
	exit(exit_co);
}

void	ft_puterr(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
}

// add more variables as they are add in structure
void	safe_init(t_parser *p)
{
	p->map_file = NULL;
	p->map = NULL;
	p->map_fd = -1;
}

// unit test
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
