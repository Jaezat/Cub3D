#include "main.h"

void	flood_sched(t_parser *p, t_stack **top, t_stack ff)
{
	*top = push(p, *top, ff.x - 1, ff.y);
	*top = push(p, *top, ff.x + 1, ff.y);
	*top = push(p, *top, ff.x, ff.y - 1);
	*top = push(p, *top, ff.x, ff.y + 1);
}

void	flood_var_init(t_parser *p, t_flood_helper *h, int x, int y)
{
	h->map = p->exec_map;
	h->start = h->map[y][x];
	h->top = NULL;
	h->top = push(p, h->top, x, y);
	if (!h->top)
		err_exit_msg("Failed to allocate memory\n", 0, p);
}

bool	flood_fill(t_parser *p, int x, int y, int pix)
{
	t_flood_helper	h;

	flood_var_init(p, &h, x, y);
	while (1)
	{
		if (h.top == NULL)
			break ;
		h.cur.x = h.top->x;
		h.cur.y = h.top->y;
		pop(&h.top);
		if (is_beyond_map_limit(p, h.cur))
			continue ;
		if (is_space_at_limit(p, h.cur, h.map))
			return (free_stack(h.top), false);
		if (h.map[h.cur.y] && h.map[h.cur.y][h.cur.x] == '1'
			|| h.map[h.cur.y][h.cur.x] == pix)
			continue ;
		if (h.map[h.cur.y][h.cur.x] == h.start)
			h.map[h.cur.y][h.cur.x] = pix;
		flood_sched(p, &h.top, h.cur);
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
