#include "header.h"

int key_hook_function(int keysym,void *param)
{
    printf("%d\n", keysym);
    if (keysym == XK_Escape)
    {
        free_all(param);
    }
    return(0);

}