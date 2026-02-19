/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 00:55:31 by wkerdad           #+#    #+#             */
/*   Updated: 2026/02/19 03:10:09 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	mouse_hook(int button, int x, int y, t_mlx *data)
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
	if (data->fractal_type == MANDELBROT)
        mandelbort(data);
    else if (data->fractal_type == JULIA){
        julia(data);}

	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img_str.mlx_img,
		0, 0);
	return (0);
}
