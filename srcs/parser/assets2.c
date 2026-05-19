#include "main.h"

// this guy needs some SERIOUS UNIT TESTING
// it runs the chars, then one space if it got here
// it then moves the argument after the id to the start of str
// it goes to the end char if its a newline it moves back one
// it then moves back to ignore all ending spaces and places '\0'
void	trim_spaces(char *str)
{
	int	start;
	int	end;

	start = 0;
	while (str[start] && str[start] != ' ')
		start++;
	start++;
	while (str[start] && str[start] == ' ')
		start++;
	copier(str, str + start, ft_strlen(str + start));
	end = ft_strlen(str) - 1;
	if (str[end] == '\n')
		end--;
	while (end >= 0 && str[end] == ' ')
	{
		end--;
	}
	str[end + 1] = 0;
}

// void	check_colors(char *str, t_parser *p)
// {

// }

void	trim_spaces_all(t_parser *p)
{
	char	**arr;
	int		i;

	arr = (char *[]){p->ea, p->no, p->so, p->we};
	i = 0;
	while (i < 4)
	{
		trim_spaces(arr[i]);
		extension_check(arr[i], ".xpm", p);
		i++;
	}
	arr = (char *[]){p->floor, p->ceiling};
	i = 0;
	while (i < 2)
	{
		trim_spaces(arr[i]);
		// check_colors(arr[i], p);
		i++;
	}
}
