#include "header.h"

int key_hook_function(int keysym, void *param)
{
    t_mlx_data *data;

    data = (t_mlx_data *)param;
    if (keysym == XK_Escape)
    {
        free_all(param);
    }
    if (keysym == XK_d)
    {
        data->disco_on = !data->disco_on;
    }
    return (0);
}