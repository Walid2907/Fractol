#include "header.h"

int disco_loop(void *param)
{
    t_mlx_data *data;

    data = (t_mlx_data *)param;
    if (!data->disco_on)
        return (0);

    data->shift = (data->shift + 1) % 360;

    draw_mandelbrot(data);
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->mlx_img, 0, 0);
    return (0);
}