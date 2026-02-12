#include "header.h"

int	color(t_mlx_data *data, int iter)
{
	int	r;
	int	g;
	int	b;

	if (iter == 100)
		return (0x000000);
	r = (int)(sin(0.3 * iter + data->color) * 127 + 128);
	g = (int)(sin(0.3 * iter + 2 + data->color) * 127 + 128);
	b = (int)(sin(0.3 * iter + 4 + data->color) * 127 + 128);
	return ((r << 16) | (g << 8) | b);
}