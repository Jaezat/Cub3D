#include "main.h"

// this considers the newline at the end, which will be removed
void	get_check_width(t_parser *p)
{
	int	curr_w;
	int	i;

	curr_w = 0;
	i = 0;
	while (p->exec_map[i])
	{
		curr_w = ft_strlen(p->exec_map[i]);
		if (curr_w > p->exec_map_w)
			p->exec_map_w = curr_w;
		i++;
	}
	if (p->exec_map_w < 3 || p->exec_map_h < 3)
		err_exit_msg("Map is tiny", 0, p);
}

void	check_valid_chars(t_parser *p)
{
	int		i;
	int		j;
	char	c;
	int		player;

	player = 0;
	i = 0;
	while (i < p->exec_map_h)
	{
		j = 0;
		while (p->exec_map[i][j])
		{
			c = p->exec_map[i][j];
			if (c != 'N' && c != 'S' && c != 'W' && c != 'E' && c != '0'
				&& c != '1' && c != '\n' && c != ' ')
				err_exit_msg("Forbidden char within map", 0, p);
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
				if (++player > 1)
					err_exit_msg("More than one player detected", 0, p);
			j++;
		}
		i++;
	}
}

void	free_matrix(void *ref, int h)
{
	int		i;
	char	**mat;

	i = 0;
	mat = *(char ***)ref;
	while (i < h)
		free(mat[i++]);
	free(mat);
}

void	flood_init(t_parser *p)
{
	char	**map;
	int		i;
	int		j;
	int		last_char;

	check_valid_chars(p);
	get_check_width(p);
	map = malloc(p->exec_map_h * sizeof(char *));
	i = 0;
	while (i < p->exec_map_h)
	{
		map[i] = malloc(p->exec_map_w);
		ft_bzero(map[i], p->exec_map_w);
		copier(map[i], p->exec_map[i], ft_strlen(p->exec_map[i]) - 1);
		space_to_wall(map[i], p->exec_map_w);
		i++;
	}
	// this is so overly confusing
	--i;
	if (p->exec_map[i] && *p->exec_map[i])
	{
		last_char = ft_strlen(p->exec_map[i]) - 1;
		map[i][last_char] = p->exec_map[i][last_char];
	}
	// printf("[%d]\n", p->exec_map_w);
	// printf("%d\n", p->exec_map_h);
	// free(map);
	// debug //////////////////////////////////////////////////////////////////
	i = 0;
	while (i < p->exec_map_h)
	{
		j = 0;
		while (j < p->exec_map_w)
		{
			printf("[%c]", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	free_matrix(&map, p->exec_map_h);
}
