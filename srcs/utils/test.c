#include "main.h" // remmeber to remove tester file

// used to test gnl function in srcs/parser/gnl.c
void	test_rem(void)
{
	int		fd;
	char	*line;

	fd = open("srcs/parser/gnl.c", O_RDONLY);
	while (1)
	{
		line = gnl(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	exit(0);
}

// used to test whether the map was loaded successfully from file to mem
void	display_map(t_parser *p)
{
	int	i;

	i = 0;
	while (i < p->exec_map_h)
	{
		printf("%s", p->exec_map[i]);
		i++;
	}
}

// printf("%x\n", (p->ceiling_hex & (0xff << (8 * 1))) >> (8 * 1));
// << 1 missing because of the way that endians work
void	print_t_parser(t_parser *p)
{
	int	i;

	printf("%s\n", p->no);
	printf("%s\n", p->so);
	printf("%s\n", p->we);
	printf("%s\n", p->ea);
	printf("%x\n", p->ceiling_hex);
	printf("%x\n", (p->ceiling_hex & (0xff << (8 * 0))) >> (8 * 0));
	printf("%x\n", (p->ceiling_hex & (0xff << (8 * 1))) >> (8 * 1));
	printf("%x\n", (p->ceiling_hex & (0xff << (8 * 2))) >> (8 * 2));
	printf("%x\n", p->floor_hex);
	printf("%x\n", (p->floor_hex & (0xff << (8 * 0))) >> (8 * 0));
	printf("%x\n", (p->floor_hex & (0xff << (8 * 1))) >> (8 * 1));
	printf("%x\n", (p->floor_hex & (0xff << (8 * 2))) >> (8 * 2));
	i = 0;
	while (p->exec_map[i])
	{
		printf("%s", p->exec_map[i]);
		i++;
	}
}

void	print_t_data(t_data *d)
{
	int	i;
	int	j;

	printf("w %d h %d\n", d->map_w, d->map_h);
	printf("%s\n", d->no);
	printf("%s\n", d->so);
	printf("%s\n", d->we);
	printf("%s\n", d->ea);
	printf("%x\n", d->sky);
	printf("%x\n", d->ground);
	i = 0;
	i = 0;
	while (i < d->map_h)
	{
		j = 0;
		while (j < d->map_w)
		{
			printf("%c ", d->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	disp_map_arr(t_parser *p)
{
	int	i;
	int	j;

	i = 0;
	while (i < p->exec_map_h)
	{
		j = 0;
		while (j < p->exec_map_w)
		{
			printf("[%c]", p->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}
