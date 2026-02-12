#include "header.h"




int	mandelbrot(double cx, double cy)
{
    double zx = 0.0;
    double zy = 0.0;
    double tmp;
    int iteration = 0;
    int max_iter = 100;

    while (zx * zx + zy * zy <= 4.0 && iteration < max_iter)
    {
        tmp = zx * zx - zy * zy + cx;
        zy = 2.0 * zx * zy + cy;
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

    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            double cx = (x - WIDTH / 2.0) * 4.0 / WIDTH;
            double cy = (y - HEIGHT / 2.0) * 4.0 / WIDTH;

            iter = mandelbrot(cx, cy);

            data->color = color(data, iter);

            my_mlx_pixel_put(data, x, y);
        }
    }
}
