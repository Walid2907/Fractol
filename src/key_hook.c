/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 00:55:19 by wkerdad           #+#    #+#             */
/*   Updated: 2026/02/19 13:56:03 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	key_hook_function(int keysym, void *param)
{
	t_mlx	*data;
	double	move_speed;

	data = (t_mlx *)param;
	move_speed = 0.5 / data->zoom;
	if (keysym == XK_Escape)
	{
		free_all((t_mlx *)param);
		exit(0);
	}
	if (keysym == XK_d)
		data->disco_on = !data->disco_on;
	else if (keysym == XK_Up)
		data->offset_y += move_speed;
	else if (keysym == XK_Down)
		data->offset_y -= move_speed;
	else if (keysym == XK_Left)
		data->offset_x -= move_speed;
	else if (keysym == XK_Right)
		data->offset_x += move_speed;
    else if (keysym == XK_minus && data->max_iter > 1)
        data->max_iter -= 1;
    else if (keysym == XK_equal)
    {
        data->max_iter += 1;
    }
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
