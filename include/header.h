#include "mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <complex.h>

#ifndef HEADER_H
# define HEADER_H

typedef struct s_mlx_data
{
    // ptr that initilize the connection with x server
    void *mlx_ptr;
    // pointer to the window
    void *mlx_window;
    // pointer to the image
    void *mlx_img;
    //number of bytes per row
    char    *addr; 
    // bits per pixel 
    int     bpp;
    // number of bytes per row
    int     line_len;

    int     endian;
    int color;
}               t_mlx_data;

# define WIDTH 1000
# define HEIGHT 1000

int key_hook_function(int keysym,void *param);
void free_all(t_mlx_data *data);
int close_window(void *param);
int mouse_hook_function(int button, int x, int y);
void my_mlx_pixel_put(t_mlx_data *data, int x, int y);
// void draw(t_mlx_data *data);
int	mandelbrot(double cx, double cy);
void draw_circle(t_mlx_data *data, int cx, int cy, int raduis);
void draw_mandelbrot(t_mlx_data *data);
int	color(t_mlx_data *data, int iter);

#endif

