// internal library headers ///////////////////////////////////////////////////
// can be broken down into smaller headers

// macros and defines /////////////////////////////////////////////////////////

// RT for return
#define RT_ERROR 1
#define RT_SUCCESS 0
// bool return for str diff
#define STR_DIFF 1
#define STR_SAME 0
// this is reasonably big for maps in the context of gnl
#define BUF_SIZE 32

// enums //////////////////////////////////////////////////////////////////////
enum		map_flag
{
	NO = 1 << 1,
	SO = 1 << 2,
	WE = 1 << 3,
	EA = 1 << 4,
	MP = 1 << 5
};

// enum		text_hex
// {
// 	NO = 1 << 0,
// 	SO = 1 << 1,
// 	WE = 1 << 2,
// 	EA = 1 << 3,
// };

// structures /////////////////////////////////////////////////////////////////

// test type to carry mlx objects
typedef struct s_umlx
{
	void	*img;
	void	*mlx;
	void	*win;
}			t_umlx;

typedef struct s_parser
{
	int		map_fd;
	char	*map_file;
	char	**map;
	char	**exec_map;
	int		exec_map_h;
	int		map_h;
	t_umlx	*u;

}			t_parser;
