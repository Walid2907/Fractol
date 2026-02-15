#include "header.h"

int close_window(void *param)
{
    t_mlx_data *data;

    data = (t_mlx_data *)param;
    mlx_destroy_image(data->mlx_ptr, data->mlx_img);
    free_all(data);
    return (0);
}