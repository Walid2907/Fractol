#include "header.h"


int	mandelbrot(double cx, double cy)
{
    double zx = 0;
    double zy = 0;
    double tmp;
    int iteration = 0;

    while (zx * zx + zy * zy <= 4 && iteration < MAX_ITER)
    {
        tmp = zx * zx - zy * zy + cx;
        zy = 2 * zx * zy + cy;
        zx = tmp;
        iteration++;
    }
    return (iteration);
}

void draw_mandelbrot(t_mlx_data *data)
{
    int x;
    int y;
    int iter;

    y = 0;

    while(y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            // move the origin from the start of the window to
            // the center of the window for x and y
            // and we scale it to -2  2 so we can get the math values
            double cx = (x - WIDTH / 2.0) * 4.0 / (WIDTH * data->zoom) + data->offset_x;
            double cy = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * data->zoom) + data->offset_y;
            iter = mandelbrot(cx, cy);
            data->color = color(data, iter);
            my_mlx_pixel_put(data, x, y);
            x++;
        }
        y++;
    }
}
