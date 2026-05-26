///////////////////////////////////////////////////////////////////////////////
#ifndef PARSER_STRUCTS_H
# define PARSER_STRUCTS_H

// internal library headers ///////////////////////////////////////////////////
// can be broken down into smaller headers

// macros and defines /////////////////////////////////////////////////////////

// RT for return
# define RT_ERROR 1
# define RT_SUCCESS 0
// bool return for str diff
# define DIFF 1
# define SAME 0
// gnl is short lived, using big buffersize makes it faster
// 1 page size 4kb * 64 to get to texture size 512 x 512
# define BUF_SIZE 4096 * 64 - 1

// enums //////////////////////////////////////////////////////////////////////

// structures /////////////////////////////////////////////////////////////////

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
	char		**map_tofree;
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