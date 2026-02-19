#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <X11/keysym.h>


#ifndef FRACTOL_H
# define FRACTOL_H

// define some numbers
# define WIDTH 600
# define HEIGHT 600
# define MAX_ITER 100
# define MANDELBROT 1
# define JULIA 2
# define TRICORN 3


// struct for the image
typedef struct s_img
{
    void *mlx_img;
    // pointer to the start of the pixels array
    void *addr;
    // bytes per pixel
    int bpp;
    //  line_lenght = WIDTH * 4 (but now a good behavioe use l_l)
    int line_length;
    //  bites order
    int endian;
}              t_img;

typedef struct s_julia
{
    double julia_x;
    double julia_y;
}               t_julia;

// struct for the mlx elements
typedef struct s_mlx
{
    void *mlx_ptr;
    void *mlx_win;
    t_img img_str;
    t_julia julia_el;
    int		color;
    int     max_iter;
    // disco controller
    int     shift;
    int     disco_on;
    // to zoom and move
    double  offset_x;
    double  offset_y;
    double  zoom;
    // fractal ttpe
    int     fractal_type;
}            t_mlx;

// Functions
void put_pixel(t_mlx *data, int x, int y, int color);
void free_all(t_mlx *data);
void mandelbort(t_mlx *data);
void julia(t_mlx *data);
void tricorn(t_mlx *data);
int key_hook_function(int keysym, void *param);
int mouse_hook(int button, int x, int y, t_mlx *data);
int disco_loop(void *param);
void    parse_input(int argc, char **argv, t_mlx *data);



# endif