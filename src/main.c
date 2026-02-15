#include "header.h"


int mlx_start(t_mlx_data *data)
{
    data->mlx_ptr = mlx_init();
    data->zoom = 1.0;
    data->offset_x = 0.0;
    data->offset_y = 0.0;

    if (data->mlx_ptr == NULL)
        return 0;

    data->mlx_window = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "test window");
    if (data->mlx_window == NULL)
    {
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
        return (0);
    }

    data->mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
    if (data->mlx_img == NULL)
    {
        free_all(data);
        return (0);
    }
    data->addr = mlx_get_data_addr(data->mlx_img, &data->bpp, &data->line_len, &data->endian);
    return (1);
}



int main()
{
    t_mlx_data mlx_data;

    if (mlx_start(&mlx_data) == 0)
        return (0);
    mlx_data.shift = 0;
    mlx_data.disco_on = 0;
    // draw pixels into image
    draw_mandelbrot(&mlx_data);
    // put image
    mlx_put_image_to_window(mlx_data.mlx_ptr, mlx_data.mlx_window, mlx_data.mlx_img, 0, 0);
    mlx_key_hook(mlx_data.mlx_window, key_hook_function, &mlx_data);
   
    mlx_hook(mlx_data.mlx_window, 17, 0, close_window, &mlx_data);

    // NEW: loop hook to animate
    mlx_loop_hook(mlx_data.mlx_ptr, disco_loop, &mlx_data);
    mlx_mouse_hook(mlx_data.mlx_window, mouse_hook, &mlx_data);
    mlx_loop(mlx_data.mlx_ptr);
    free_all(&mlx_data);
}