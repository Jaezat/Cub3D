#include "main.h"

// segfault at the last line deref when NULL
void	check_borders(t_parser *p)
{
	int	i;

	i = 0;
	while (i < p->exec_map_h - 1)
	{
		if (p->map[i][0] != '1')
			err_exit_msg("There is a void on the map", 0, p);
		if (p->map[i][p->exec_map_w - 2] != '1')
			err_exit_msg("There is a void on the map", 0, p);
		i++;
	}
	i = 0;
	while (i < p->exec_map_w - 2)
	{
		if (p->map[0][i] != '1')
			err_exit_msg("There is a void on the map", 0, p);
		if (p->map[p->exec_map_h - 1])
			if (p->map[p->exec_map_h - 1][i] != '1')
				err_exit_msg("There is a void on the map", 0, p);
		i++;
	}
}

typedef struct s_stack
{
	int				x;
	int				y;
	struct s_stack	*next;
}					t_stack;

void	pop(t_stack **old_top)
{
	t_stack	*tmp;

	if (*old_top)
	{
		tmp = *old_top;
		*old_top = (*old_top)->next;
		free(tmp);
	}
	
}

void	free_stack(t_stack *top)
{
	t_stack	*tmp;

	while (top)
	{
		pop(&top);
	}
}

t_stack	*push(t_parser *p, t_stack *old_top, int x, int y)
{
	t_stack	*new_top;

	new_top = malloc(sizeof(t_stack));
	if (new_top == NULL)
	{
		while (old_top)
		{
			pop(&old_top);
		}
		
		err_exit_msg("Memory failure on map verification\n", 0, p);
		return (NULL);
	}
	new_top->x = x;
	new_top->y = y;
	new_top->next = old_top;
	return (new_top);
}

void	p_stack(t_stack *top)
{
	while (top)
	{
		printf("%d %d\n", top->x, top->y);
		// pop(&top);
		top = top->next;
	}
}

void	disp_map(t_parser *p)
{
	int	i;
	int	j;

	i = 0;
	if (p->exec_map)
		while (i < p->exec_map_h && p->exec_map[i])
		{
			j = 0;
			while (j < p->exec_map_w)
			{
				if (p->exec_map[i][j] == '\0')
					printf(" |");
				else if (p->exec_map[i][j] == '\n')
					printf(" |");
				else if (p->exec_map[i][j] == '1')
					printf("█|");
				else
					printf("%c|", p->exec_map[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}
	printf("_______________\n");
}

typedef struct s_flood_helper
{
}					t_flood_helper;

void	flood_sched(t_parser *p, t_stack **top, t_stack ff)
{
	*top = push(p, *top, ff.x - 1, ff.y);
	*top = push(p, *top, ff.x + 1, ff.y);
	*top = push(p, *top, ff.x, ff.y - 1);
	*top = push(p, *top, ff.x, ff.y + 1);
}

bool	is_space_at_limit(t_parser *p, t_stack ff, char **map)
{
	return (ff.y == 0 && map[ff.y][ff.x] == '0') || (ff.x == 0
		&& map[ff.y][ff.x] == '0') || (ff.y == p->exec_map_h
		&& map[ff.y][ff.x] == '0') || (ff.x == p->exec_map_w - 2
		&& map[ff.y][ff.x] == '0');
}

bool	is_beyond_map_limit(t_parser *p, t_stack ff)
{
	return (ff.y < 0 || ff.x < 0 || ff.y > p->exec_map_h || ff.x > p->exec_map_w
		- 2);
}

bool	flood_fill(t_parser *p, int x, int y, int target)
{
	t_stack	*top;
	t_stack	fl;
	int		start;
	char	**map;

	map = p->exec_map;
	start = map[y][x];
	top = NULL;
	top = push(p, top, x, y);
	if (!top)
		return (false);	
	while (1)
	{
		if (top == NULL)
			break ;
		fl.x = top->x;
		fl.y = top->y;
		pop(&top);
		if (is_beyond_map_limit(p, fl))
			continue ;
		if (is_space_at_limit(p, fl, map))
			return (free_stack(top), false);
		if (map[fl.y] && map[fl.y][fl.x] == '1' || map[fl.y][fl.x] == target)
			continue ;
		if (map[fl.y][fl.x] == start)
			map[fl.y][fl.x] = target;
		flood_sched(p, &top, fl);
	}
	return (true);
}

void	start_flooding(t_parser *p)
{
	int		i;
	int		j;
	char	dir;

	i = 0;
	while (i < p->exec_map_h && p->exec_map[i])
	{
		j = 0;
		while (j < p->exec_map_w - 2)
		{
			if (p->exec_map[j][i] == 'N' || p->exec_map[j][i] == 'E'
				|| p->exec_map[j][i] == 'W' || p->exec_map[j][i] == 'S')
			{
				dir = p->exec_map[j][i];
				p->exec_map[j][i] = '0';
				if (!flood_fill(p, j, i, '*'))
					err_exit_msg("There is a hole on the map!\n", 0, p);
				flood_fill(p, j, i, '0');
				p->exec_map[j][i] = dir;
			}
			j++;
		}
		i++;
	}
}
