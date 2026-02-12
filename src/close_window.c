#include "header.h"

int close_window(void *param)
{
    t_mlx_data *data;

    data = (t_mlx_data *)param;
    free_all(data);
    return (0);
}