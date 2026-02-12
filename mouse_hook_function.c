#include "header.h"

int mouse_hook_function(int button, int x, int y)
{
    printf("button: %d, x: %d, y: %d\n", button, x, y);
    return (0);
}