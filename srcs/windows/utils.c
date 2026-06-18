#include "main.h"

bool check_margin(t_data *data, float *new_y, float *new_x)
{
	char **map;

	map = data->map;
	if (*new_y < 0 || *new_y >= MAP_H)
		return (false);
	if (*new_x < 0 || *new_x >= MAP_W)
		return (false);	
	if (map[(int)*new_y][(int)*new_x] == '1')
		return (false);
	return (true);
}

// void checking_position(t_data *data, float *new_y, float *new_x)
// {
//     float x_plus;
//     float x_minus;
//     float y_plus;
//     float y_minus;

// 	x_plus = *new_x + MARGIN;
// 	x_minus = *new_x - MARGIN;
// 	y_plus = *new_y + MARGIN;
// 	y_minus = *new_y - MARGIN;
//     if (check_margin(data, new_y, &x_plus) && check_margin(data, new_y, &x_minus))
//     {
//         printf("\nPX before: %f\n", data->px);
//         data->px = *new_x;
//         printf("PX after: %f\n", data->px);
//     }
//     if (check_margin(data, &y_plus, new_x) && check_margin(data, &y_minus, new_x))
//     {
//         printf("\nPY before: %f\n", data->py);
//         data->py = *new_y;
//         printf("PY after: %f\n", data->py);
//     }
// }

void checking_position(t_data *data, float *new_y, float *new_x)
{
    float x_plus = *new_x + MARGIN;
    float x_minus = *new_x - MARGIN;
    float y_plus = *new_y + MARGIN;
    float y_minus = *new_y - MARGIN;

    // 1. EVALUAR Y APLICAR X (Independiente de Y)
    // Pasamos data->py (la posición actual real) en lugar de new_y para evitar interferencias
    if (check_margin(data, &data->py, &x_plus) 
        && check_margin(data, &data->py, &x_minus))
    {
        data->px = *new_x;
    }

    // 2. EVALUAR Y APLICAR Y (Independiente de X)
    // Pasamos data->px (la posición actual real) en lugar de new_x
    if (check_margin(data, &y_plus, &data->px) 
        && check_margin(data, &y_minus, &data->px))
    {
        data->py = *new_y;
    }
}
