///////////////////////////////////////////////////////////////////////////////
#ifndef P_STRUCTS_H
# define P_STRUCTS_H

// RT means return
# define RT_ERROR 1
# define RT_SUCCESS 0
// for confusing return numbers
# define DIFF 1
# define SAME 0
// to fit a page size
# define BUF_SIZE 4096 - 1

# define R 0xff0000
# define G 0x00ff00
# define B 0x0000ff

typedef struct s_img
{
	int			w;
	int			h;
	void		*ptr;
}				t_img;

typedef struct s_data
{
	char		**map;
	int			sky;
	int			ground;
	int			map_h;
	int			map_w;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	t_img		imgs[4];
	float		dir;
	float		px;
	float		py;
}				t_data;

typedef struct s_parser
{
	int			map_fd;
	char		*map_file;
	char		**map_head;
	char		**exec_map;
	int			map_h;
	char		*floor;
	char		*ceiling;
	char		*rgb_f[3];
	char		*rgb_c[3];
	int			hex_f[3];
	int			hex_c[3];
	char		**map;
	int			ceiling_hex;
	int			floor_hex;
	int			exec_map_h;
	int			exec_map_w;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
}				t_parser;

#endif
///////////////////////////////////////////////////////////////////////////////