#include "header.h"

// wheel up to zoom in 
// wheel down to zoom out

int mouse_hook(int button, int x, int y, t_mlx_data *data)
{
    double mouse_re;
    double mouse_im;
    double zoom_factor = 1.1;

    // Convert pixel to complex plane BEFORE zoom change
    mouse_re = (x - WIDTH / 2.0) * 4.0 / (WIDTH * data->zoom) + data->offset_x;
    mouse_im = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * data->zoom) + data->offset_y;

    if (button == 4) // scroll up → zoom in
        data->zoom *= zoom_factor;
    else if (button == 5) // scroll down → zoom out
        data->zoom /= zoom_factor;

    // Adjust offsets so zoom centers at mouse
    data->offset_x = mouse_re - (x - WIDTH / 2.0) * 4.0 / (WIDTH * data->zoom);
    data->offset_y = mouse_im - (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * data->zoom);

    draw_mandelbrot(data);
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->mlx_img, 0, 0);
    return (0);
}
