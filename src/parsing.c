/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:18:34 by wkerdad           #+#    #+#             */
/*   Updated: 2026/02/19 18:07:40 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	error_exit(void)
{
	write(2, "Usage:\n", 7);
	write(2, "./fractol mandelbrot\n", 21);
	write(2, "./fractol julia <real> <imag>\n", 30);
	write(2, "./fractol tricorn\n", 18);
	exit(1);
}

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s_1;
	unsigned char	*s_2;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	i = 0;
	s_1 = (unsigned char *)s1;
	s_2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n && (*s_1 || *s_2))
	{
		if (*s_1 != *s_2)
			return (*s_1 - *s_2);
		s_1++;
		s_2++;
		i++;
	}
	return (0);
}

void	parse_input(int argc, char **argv, t_mlx *data)
{
	if (argc == 2 && ft_strncmp(argv[1], "mandelbrot", 11) == 0)
	{
		data->fractal_type = MANDELBROT;
	}
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 6) == 0)
	{
		if (!is_valid_number(argv[2]) || !is_valid_number(argv[3]))
			error_exit();
		data->fractal_type = JULIA;
		data->julia_el.julia_x = ft_atof(argv[2]);
		data->julia_el.julia_y = ft_atof(argv[3]);
	}
	else if (ft_strncmp(argv[1], "tricorn", 8) == 0)
		data->fractal_type = TRICORN;
	else
		error_exit();
}
