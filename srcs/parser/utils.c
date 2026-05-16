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
void	exit_routine(void *ref)
{
	free(ref);
	exit(EXIT_FAILURE);
}

void	ft_puterr(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
}
