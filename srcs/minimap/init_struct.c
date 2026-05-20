#include "cub3d.h"

int struct_init(t_cubed **cub) // rwork ont this
{
    *cub = calloc(1, sizeof(t_cubed));
    if (!*cub)
        return (1);
    (*cub)->map = calloc(1, sizeof(t_map));
    if (!(*cub)->map)
    {
        free(*cub);
        return (1);
    }
    (*cub)->map->img_str = calloc(1, sizeof(t_img));
    if (!(*cub)->map->img_str)
    {
        free((*cub)->map);
        free(*cub);
        return (1);
    }
    return (0);
}