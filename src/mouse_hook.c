/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 00:55:31 by wkerdad           #+#    #+#             */
/*   Updated: 2026/02/19 14:15:11 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	calcules_man(t_mlx *data, int x, int y, int button)
{
	double	mouse_re;
	double	mouse_im;
	double	zoom_factor;

	zoom_factor = 1.1;
	mouse_re = -2.0 + (x * 3.0 / WIDTH) / data->zoom + data->offset_x;
	mouse_im = 1.5 - (y * 3.0 / HEIGHT) / data->zoom + data->offset_y;
	if (button == 4)
		data->zoom *= zoom_factor;
	else if (button == 5)
		data->zoom /= zoom_factor;
	data->offset_x = mouse_re - (-2.0 + (x * 3.0 / WIDTH) / data->zoom);
	data->offset_y = mouse_im - (1.5 - (y * 3.0 / HEIGHT) / data->zoom);
}

static void	calcules_jul_tri(t_mlx *data, int x, int y, int button)
{
	double	mouse_re;
	double	mouse_im;
	double	zoom_factor;

	zoom_factor = 1.1;
	mouse_re = -2.0 + (x * 4.0 / WIDTH) / data->zoom + data->offset_x;
	mouse_im = 2 - (y * 4.0 / HEIGHT) / data->zoom + data->offset_y;
	if (button == 4)
		data->zoom *= zoom_factor;
	else if (button == 5)
		data->zoom /= zoom_factor;
	data->offset_x = mouse_re - (-2.0 + (x * 4.0 / WIDTH) / data->zoom);
	data->offset_y = mouse_im - (2 - (y * 4.0 / HEIGHT) / data->zoom);
}

int	mouse_hook(int button, int x, int y, t_mlx *data)
{
	if (data->fractal_type == MANDELBROT)
	{
		calcules_man(data, x, y, button);
		mandelbort(data);
	}
	else if (data->fractal_type == JULIA)
	{
		calcules_jul_tri(data, x, y, button);
		julia(data);
	}
	else if (data->fractal_type == TRICORN)
	{
		calcules_jul_tri(data, x, y, button);
		tricorn(data);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img_str.mlx_img,
		0, 0);
	return (0);
}
