#include "header.h"


// esc to quit'
// d to turn on disco
int key_hook_function(int keysym, void *param)
{
    t_mlx_data *data;

    data = (t_mlx_data *)param;
    if (keysym == XK_Escape)
    {
        mlx_destroy_image(data->mlx_ptr, data->mlx_img);
        free_all(param);
    }
    if (keysym == XK_d)
        data->disco_on = !data->disco_on;

    return (0);
}