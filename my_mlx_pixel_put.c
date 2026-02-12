#include "header.h"

void my_mlx_pixel_put(t_mlx_data *data, int x, int y)
{
    char *dst;

    /*
        addr is a pointer to the start of the memory of the image
        the pixels in the memory are 1D so we need some math so it becomes 2D
        y * line_len to move one row down
        x * bpp / 8 to move one column
    */
    dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
    *(unsigned int *)dst = data->color;
}

// void draw(t_mlx_data *data)
// {
//     int x;
//     int y;
//     data->color = 0x00FF0000;

//     y = 0;
//     while (y < HEIGHT)
//     {
//         x = 0;
//         while (x < WIDTH)
//         {
//             my_mlx_pixel_put(data, x, y);
//             x++;
//         }
//         y++;
//     }
// }

