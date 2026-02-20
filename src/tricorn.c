/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:42:39 by wkerdad           #+#    #+#             */
/*   Updated: 2026/02/19 17:59:29 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	color(t_mlx *data, int iter)
{
	int	gray;

	if (iter == data->max_iter)
		return (0x000000);
	gray = (int)(sin(0.3 * iter + data->shift) * 127 + 128);
	return ((gray << 16) | (gray << 8) | gray);
}

static int	tricorn_form(t_mlx *data, double x, double y)
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
		new_y = -2.0 * new_x * new_y + y;
		new_x = temp;
		iteration++;
	}
	return (iteration);
}

void	tricorn(t_mlx *data)
{
	int		x;
	int		y;
	double	x_real;
	double	y_imaginary;
	int		iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			x_real = -2.0 + (x * 4.0 / WIDTH) / data->zoom + data->offset_x;
			y_imaginary = 2 - (y * 4.0 / HEIGHT) / data->zoom + data->offset_y;
			helper_rotate(&x_real, &y_imaginary, data);
			iter = tricorn_form(data, x_real, y_imaginary);
			data->color = color(data, iter);
			put_pixel(data, x, y, data->color);
			x++;
		}
		y++;
	}
}
