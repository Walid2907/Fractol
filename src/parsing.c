#include <fractol.h>

static void error_exit(void)
{
    write(2, "Usage:\n", 7);
    write(2, "./fractol mandelbrot\n", 21);
    write(2, "./fractol julia <real> <imag>\n", 30);
    exit(1);
}

static int is_valid_number(char *str)
{
    int i = 0;

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

double	ft_atof(const char *s)
{
	double	n;
	double	sign;
	double	pow;

	n = 0.0;
	sign = 1.0;
	pow = 1.0;

	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
		sign = (*s++ == '-') ? -1.0 : 1.0;
	while (*s >= '0' && *s <= '9')
		n = n * 10.0 + (*s++ - '0');
	if (*s == '.')
	{
		s++;
		while (*s >= '0' && *s <= '9')
		{
			pow /= 10.0;
			n += (*s++ - '0') * pow;
		}
	}
	return (n * sign);
}



void    parse_input(int argc, char **argv, t_mlx *data)
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

