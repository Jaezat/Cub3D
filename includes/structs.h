typedef struct s_img
{
	int					w;
	int					h;
	void				*ptr;
}						t_img;

typedef struct s_data
{
	char				**map;
	int					sky;
	int					ground;
	int					map_h;
	int					map_w;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	t_img				imgs[4];
	float				dir;
	float				px;
	float				py;
}						t_data;

typedef struct s_parser
{
	int					map_fd;
	char				*map_file;
	char				**map_head;
	char				**exec_map;
	int					map_h;
	char				*floor;
	char				*ceiling;
	char				*rgb_f[3];
	char				*rgb_c[3];
	int					hex_f[3];
	int					hex_c[3];
	char				**map;
	int					ceiling_hex;
	int					floor_hex;
	int					exec_map_h;
	int					exec_map_w;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
}						t_parser;

typedef struct s_camera
{
	int					radius;
	int					top;
	int					bot;
	int					left;
	int					right;
}						t_cam;

typedef struct s_draw
{
	int					map_y;
	int					map_x;
	int					px_y;
	int					px_x;
	int					screen_x;
	int					screen_y;
	unsigned int		color;
	char				c_map;
}						t_draw;

typedef struct s_minimap
{
	t_draw				wdw;
	t_cam				cam;
	int					i;
}						t_minimap;

typedef struct s_keys
{
	int					w;
	int					a;
	int					s;
	int					d;
	int					left;
	int					right;
}						t_keys;

typedef struct s_img_data
{
	int					bpp;
	int					endian;
	int					line_s;
	int					*addr;
}						t_img_data;

typedef struct s_umlx
{
	void				*img;
	void				*mlx;
	void				*win;
	t_img_data			img_data;
}						t_umlx;

typedef struct s_game
{
	t_data				*data;
	t_umlx				umlx;
	t_minimap			mini;
	t_keys				keys;
}						t_env;