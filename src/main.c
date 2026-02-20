/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 00:55:22 by wkerdad           #+#    #+#             */
/*   Updated: 2026/02/19 17:21:29 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int	close_window(t_mlx *data)
{
	free_all(data);
	return (0);
}

void	data_init(t_mlx *data)
{
	data->shift = 0;
	data->disco_on = 0;
	data->zoom = 1.0;
	data->offset_x = 0.0;
	data->offset_y = 0.0;
	data->max_iter = MAX_ITER;
	data->angle = 0.0;
}

static int	mlx_initializer(t_mlx *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (0);
	data->mlx_win = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Fractol");
	if (data->mlx_win == NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		return (0);
	}
	data->img_str.mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (data->img_str.mlx_img == NULL)
	{
		mlx_destroy_display(data->mlx_ptr);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		return (0);
	}
	data->img_str.addr = mlx_get_data_addr(data->img_str.mlx_img,
			&data->img_str.bpp, &data->img_str.line_length,
			&data->img_str.endian);
	if (data->img_str.addr == NULL)
	{
		free_all(data);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_mlx	data;

	parse_input(argc, argv, &data);
	if (mlx_initializer(&data) == 0)
		return (0);
	data_init(&data);
	if (data.fractal_type == MANDELBROT)
		mandelbort(&data);
	else if (data.fractal_type == JULIA)
		julia(&data);
	else if (data.fractal_type == TRICORN)
	{
		tricorn(&data);
	}
	mlx_key_hook(data.mlx_win, key_hook_function, &data);
	mlx_mouse_hook(data.mlx_win, mouse_hook, &data);
	mlx_loop_hook(data.mlx_ptr, disco_loop, &data);
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img_str.mlx_img, 0,
		0);
	mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	mlx_loop(data.mlx_ptr);
}
