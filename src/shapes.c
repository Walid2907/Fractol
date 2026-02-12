#include "header.h"

void draw_circle(t_mlx_data *data, int cx, int cy, int raduis)
{
    int x = 0;
    int y = -raduis;
    double y_mid;
    while(x < -y)
    {
        y_mid = y + 0.5;
        if (x*x + y_mid * y_mid > raduis*raduis)
            y++;
        my_mlx_pixel_put(data, cx + x, cy + y);
        my_mlx_pixel_put(data, cx - x, cy + y);
        my_mlx_pixel_put(data, cx + x, cy - y);
        my_mlx_pixel_put(data, cx - x, cy - y);

        my_mlx_pixel_put(data, cx + y, cy + x);
        my_mlx_pixel_put(data, cx - y, cy + x);
        my_mlx_pixel_put(data, cx + y, cy - x);
        my_mlx_pixel_put(data, cx - y, cy - x);
        x++;
    }
    x = 0;
    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            if(pow(x-cx, 2) + pow(y-cy, 2) >= pow(raduis, 2))
                my_mlx_pixel_put(data, x, y);
            x++;
        }
        y++;
    }

}