// internal library headers ///////////////////////////////////////////////////
// can be broken down into smaller headers

// macros and defines /////////////////////////////////////////////////////////

// RT for return
#define RT_ERROR 1
#define RT_SUCCESS 0
// bool return for str diff
#define DIFF 1
#define SAME 0
// gnl is short lived, using big buffersize makes it faster
// 1 page size 4kb * 64 to get to texture size 512 x 512
#define BUF_SIZE 4096 * 64 - 1

// enums //////////////////////////////////////////////////////////////////////
// enum		map_flag
// {
// 	NO = 1 << 1,
// 	SO = 1 << 2,
// 	WE = 1 << 3,
// 	EA = 1 << 4,
// 	MP = 1 << 5
// };

// structures /////////////////////////////////////////////////////////////////

// test type to carry mlx objects
typedef struct s_umlx
{
	void			*img;
	void			*mlx;
	void			*win;
}					t_umlx;

// u can be removed later depending on context
// t_umlx	*u;
typedef struct s_parser
{
	int				map_fd;
	char			*map_file;
	char			**map_tofree;
	char			**exec_map;
	int				exec_map_h;
	int				exec_map_w;
	int				map_h;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*floor;
	char			*ceiling;
	char			*rgb_f[3];
	char			*rgb_c[3];
	int				hex_f[3];
	int				hex_c[3];
	unsigned int	floor_hex;
	unsigned int	ceiling_hex;
}					t_parser;
