#include "main.h"

// TODO: unit test this file and then the function
size_t	line_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	if (str[i] == '\n')
		i++;
	return (i);
}

bool	has_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (true);
		i++;
	}
	return (false);
}

void	copier(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	if (src)
	{
		while (src[i] && len--)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
}

char	*joiner(char *line, char *buf)
{
	int		line_size;
	int		buf_size;
	char	*newline;

	line_size = line_len(line);
	buf_size = line_len(buf);
	newline = malloc(line_size + buf_size + 1);
	if (!newline)
		return (NULL);
	copier(newline, line, line_size);
	free(line);
	copier(newline + line_size, buf, buf_size);
	return (newline);
}

// added + 1 in buf size and didnt test yet
// what is gnl fails from bad read, how can i tell outside
// does it matter? will have partial map and will be invalidated
// or lucky and gets validated
char	*gnl(int fd)
{
	static char	buf[BUF_SIZE + 1];
	int			r_size;
	char		*line;

	line = NULL;
	while (1)
	{
		if (!*buf)
		{
			r_size = read(fd, buf, BUF_SIZE);
			if (r_size == 0)
				return (line);
			if (r_size == -1)
				return (free(line), NULL);
			buf[r_size] = 0;
		}
		line = joiner(line, buf);
		copier(buf, buf + line_len(buf), ft_strlen(buf));
		if (has_line(line))
			return (line);
	}
}
