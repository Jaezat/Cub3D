#ifndef STRUCTS_H
# define STRUCTS_H

# define RT_ERROR   1
# define RT_SUCCESS 0
# define SAME       0
# define BUF_SIZE   4095

typedef struct s_img
{
	int				w;
	int				h;
	void			*ptr;
}					t_img;

typedef struct s_keys
{
	int					w;
	int					a;
	int					s;
	int					d;
	int					left;
	int					right;
}						t_keys;

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
	float		dir_x;
	float		dir_y;
	float		px;
	float		py;
	t_keys		key;
}				t_data;

typedef struct s_parser
{
	int				map_fd;
	char			*map_file;
	char			**map_head;
	char			**exec_map;
	int				map_h;
	char			*floor;
	char			*ceiling;
	char			*rgb_f[3];
	char			*rgb_c[3];
	int				hex_f[3];
	int				hex_c[3];
	char			**map;
	int				ceiling_hex;
	int				floor_hex;
	int				exec_map_h;
	int				exec_map_w;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
}					t_parser;

typedef struct s_camera
{
    double x; // coordenada x de donde empieza la camara en el mapa
    double y; // coordenada y de donde empieza la camara
    double limit_x;
    double limit_y;
    unsigned int c;
}   t_cam;

typedef struct s_draw
{
	int				map_y;
	int				map_x;
	int				px_y;
	int				px_x;
	int				screen_x;
	int				screen_y;
	unsigned int	color;
	char			c_map;
}					t_draw;

typedef struct s_minimap
{
    t_cam       cam;
    int i;
}   t_minimap; 

typedef struct s_img_data
{
	int				bpp;
	int				endian;
	int				line_s;
	int				*addr;
}					t_img_data;

typedef struct s_umlx
{
	void			*img;
	void			*mlx;
	void			*win;
	t_img_data		img_data;
}					t_umlx;

typedef struct s_angle
{
	float			dir_x;
	float			dir_y;
	float			plane_x;
	float			plane_y;// void	load_textures(t_umlx *u)
// {
// 	t_data	*d;
// 	t_img	*img;
// 	int		i;
// 	char	**arr;

// 	d = u->d;
// 	arr = (char *[]){d->no, d->so, d->ea, d->we};
// 	i = 0;
// 	while (i < 4)
// 	{
// 		img = &d->imgs[i];
// 		img->ptr = mlx_xpm_file_to_image(u->mlx, arr[i], &img->w, &img->h);
// 		if (!img->ptr)
// 		{
// 			ft_puterr("Error\nFailed to load textures\n");
// 			exit_exec(u, 1);
// 		}
// 		i++;
// 	}
// }

}					t_angle;

typedef struct s_env
{
	t_data			*data;
	t_umlx			umlx;
	t_minimap		minimap;
	t_keys			keys;
	t_angle			angle;
}					t_env;

#endif