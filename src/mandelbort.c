/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 00:54:47 by wkerdad           #+#    #+#             */
/*   Updated: 2026/02/19 17:54:59 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int	color(t_mlx *data, int iter)
{
	int	gray;

	if (iter == data->max_iter)
		return (0x000000);
	gray = (int)(sin(0.3 * iter + data->shift) * 127 + 128);
	return ((gray << 16) | (gray << 8) | gray);
}

// function that check if the number escape or not
// return number of iterations to choose the color
static int	mandelbort_form(t_mlx *data, double x, double y)
{
	double	new_x;
	double	new_y;
	double	temp;
	int		iteration;

	new_x = 0.0;
	new_y = 0.0;
	iteration = 0;
	while (iteration < data->max_iter)
	{
		if (new_x * new_x + new_y * new_y > 4.0)
			break ;
		temp = new_x * new_x - new_y * new_y + x;
		new_y = 2.0 * new_x * new_y + y;
		new_x = temp;
		iteration++;
	}
	return (iteration);
}

// limits for x are -2->1
// limits for y are -1.5->1.5
// !!!! test first if not change to -2 -> 2 for both
// value z or y
// old_min 0  for both
// old_max Width or Height for x,y
// new min and new max look at the limits up
// formul for maping new_value = new_min + (value - old_min) * (new_max
//		- new_min) / (old_max - old_min)
// the maping function
//            x_Real = -2.0 + (x * 3.0 / WIDTH) / data->zoom + data->offset_x;
//            y_Imaginary = 1.5 - (y * 3.0 / HEIGHT) / data->zoom
//	+ data->offset_y;

void	helper_rotate(double *x_real, double *y_imag, t_mlx *data)
{
	double	tmp;

	tmp = *x_real;
	*x_real = tmp * cos(data->angle) - *y_imag * sin(data->angle);
	*y_imag = tmp * sin(data->angle) + *y_imag * cos(data->angle);
}

void	mandelbort(t_mlx *data)
{
	int		x;
	int		y;
	double	x_real;
	double	y_imag;
	int		iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			x_real = -2.0 + (x * 3.0 / WIDTH) / data->zoom + data->offset_x;
			y_imag = 1.5 - (y * 3.0 / HEIGHT) / data->zoom + data->offset_y;
			helper_rotate(&x_real, &y_imag, data);
			iter = mandelbort_form(data, x_real, y_imag);
			data->color = color(data, iter);
			put_pixel(data, x, y, data->color);
			x++;
		}
		y++;
	}
}
