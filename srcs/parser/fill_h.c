#include <main.h>

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

bool	is_space_at_limit(t_parser *p, t_stack ff, char **map)
{
	bool	ret;

	ret = (ff.y == 0 && map[ff.y][ff.x] == '0') || (ff.x == 0
			&& map[ff.y][ff.x] == '0') || (ff.y == p->exec_map_h - 1
			&& map[ff.y][ff.x] == '0') || (ff.x == p->exec_map_w - 2
			&& map[ff.y][ff.x] == '0' || map[ff.y][ff.x] == 'X');
	return (ret);
}

bool	is_beyond_map_limit(t_parser *p, t_stack ff)
{
	return (ff.y < 0 || ff.x < 0 || ff.y > p->exec_map_h - 1 || ff.x > p->exec_map_w
		- 2);
}
