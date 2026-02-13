#include "header.h"

int	color(t_mlx_data *data, int iter)
{
	int	gray;

	if (iter == 100)
		return (0x000000);
	// grayscale wave, shifts over time
	gray = (int)(sin(0.3 * iter + data->shift) * 127 + 128);
	return ((gray << 16) | (gray << 8) | gray);
}