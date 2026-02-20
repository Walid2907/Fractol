/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:37:01 by wkerdad           #+#    #+#             */
/*   Updated: 2026/02/19 18:07:56 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <X11/keysym.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// define some numbers
# define WIDTH 600
# define HEIGHT 600
# define MAX_ITER 100
# define MANDELBROT 1
# define JULIA 2
# define TRICORN 3

// struct for the image
// pointer to the start of the pixels array
// bytes per pixel
//  line_lenght = WIDTH * 4 (but now a good behavioe use l_l)
//  bites order
typedef struct s_img
{
	void	*mlx_img;
	void	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_img;

// struct for the mlx elements
typedef struct s_julia
{
	double	julia_x;
	double	julia_y;
}			t_julia;

// disco controller
// to zoom and move
// fractal ttpe
typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	img_str;
	t_julia	julia_el;
	int		color;
	int		max_iter;
	int		shift;
	int		disco_on;
	double	offset_x;
	double	offset_y;
	double	zoom;
	int		fractal_type;
	double	angle;
}			t_mlx;

// Functions
void		put_pixel(t_mlx *data, int x, int y, int color);
void		free_all(t_mlx *data);
void		mandelbort(t_mlx *data);
void		julia(t_mlx *data);
void		tricorn(t_mlx *data);
int			key_hook_function(int keysym, void *param);
int			mouse_hook(int button, int x, int y, t_mlx *data);
int			disco_loop(void *param);
void		parse_input(int argc, char **argv, t_mlx *data);
void		data_init(t_mlx *data);
void		helper_rotate(double *x_real, double *y_imag, t_mlx *data);
double		ft_atof(const char *str);

#endif