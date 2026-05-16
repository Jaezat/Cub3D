#include "main.h"

void	ft_puterr(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
}

void	err_exit_msg(char *msg, char *arg)
{
	ft_puterr("Error\n");
	ft_puterr(msg);
	if (arg)
		ft_puterr(arg);
	ft_puterr("\n");
	// insert cleanup routine here
	exit_routine(NULL);
	exit(1);
}

bool	is_cubed_ext(char *filename, char *extension)
{
	int	i;

	i = 0;
	while (filename[i])
	{
		if (filename[i] != extension[i])
			return (false);
		i++;
	}
	return (true);
}
