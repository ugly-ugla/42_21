#include "../includes/fdf.h"

void    window(t_fdf *fdf, int width, int height, char *title)
{
    fdf->mlx_ptr = mlx_init();
    fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, width, height, title);
    draw(fdf);
    mlx_key_hook(fdf->win_ptr, deal_key, NULL);
    mlx_loop(fdf->mlx_ptr;)
}
