/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disco_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 00:55:00 by wkerdad           #+#    #+#             */
/*   Updated: 2026/02/19 13:50:01 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	disco_loop(void *param)
{
	t_mlx	*data;

	data = (t_mlx *)param;
	if (!data->disco_on)
		return (0);
	data->shift = (data->shift + 1) % 360;
	if (data->fractal_type == MANDELBROT)
		mandelbort(data);
	else if (data->fractal_type == JULIA)
		julia(data);
	else if (data->fractal_type == TRICORN)
	{
		tricorn(data);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img_str.mlx_img,
		0, 0);
	return (0);
}
