#include "main.h"

void errmsg(char *msg)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, msg, ft_strlen(msg));
}
