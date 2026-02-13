#include "header.h"

int main()
{
    t_mlx_data mlx_data;

    mlx_data.mlx_ptr = mlx_init();
    if (mlx_data.mlx_ptr == NULL)
        return 0;

    mlx_data.mlx_window = mlx_new_window(mlx_data.mlx_ptr, WIDTH, HEIGHT, "test window");
    if (mlx_data.mlx_window == NULL)
    {
        mlx_destroy_display(mlx_data.mlx_ptr);
        free(mlx_data.mlx_ptr);
       return (0);
    }
    mlx_data.mlx_img = mlx_new_image(mlx_data.mlx_ptr, WIDTH, HEIGHT);
    mlx_data.addr = mlx_get_data_addr(mlx_data.mlx_img, &mlx_data.bpp, &mlx_data.line_len, &mlx_data.endian);

    mlx_data.shift = 0;
    mlx_data.disco_on = 0;

    draw_mandelbrot(&mlx_data);  // draw pixels into image

    mlx_put_image_to_window(mlx_data.mlx_ptr, mlx_data.mlx_window, mlx_data.mlx_img, 0, 0);
    mlx_key_hook(mlx_data.mlx_window, key_hook_function, &mlx_data);
    // mlx_string_put(mlx_data.mlx_ptr, mlx_data.mlx_window, 50, 50, 0xFF0000, "walid nadi");
    mlx_mouse_hook(mlx_data.mlx_window, mouse_hook_function, &mlx_data);
    mlx_hook(mlx_data.mlx_window, 17, 0, close_window, &mlx_data);

    // NEW: loop hook to animate
    mlx_loop_hook(mlx_data.mlx_ptr, disco_loop, &mlx_data);

    mlx_loop(mlx_data.mlx_ptr);

    free_all(&mlx_data);
}