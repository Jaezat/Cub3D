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
	int		map_h;
	t_umlx	*u;

}			t_parser;
