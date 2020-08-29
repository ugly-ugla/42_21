#include "fdf.h"

void    window(fdf *data, int width, int height, char *title)
{
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, title);
    draw(x,y,x1,y1,data);
    mlx_key_hook(data->win_ptr, deal_key, NULL);
    mlx_loop(data->mlx_ptr;)
}
