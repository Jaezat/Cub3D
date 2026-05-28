#ifndef WDW_MLX_STRUCT_H
#define WDW_MLX_STRUCT_H


typedef struct s_img_data
{
	int			bpp;
	int			endian;
	int			line_s;
	int			*addr;
}				t_img_data;

typedef struct s_umlx
{
	void		*img;
	void		*mlx;
	void		*win;
	t_data		*d;
	t_img_data	img_data;
}				t_umlx;

#endif