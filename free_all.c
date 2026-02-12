#include "header.h"

void free_all(t_mlx_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->mlx_window);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
    exit(0);
}