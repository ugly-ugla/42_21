#include "fdf.h"

void    isometric

//turn to funcs like isometric and parallel
XPUT (x_count + Z * ANGLE_X / 42) * ZOOM
# define YPUT (y_count + Z * ANGLE_Y / 42) * ZOOM
# define XISO XPUT - YPUT
# define YISO (XPUT + YPUT) / 2

if (mlx->projection == 1)
		there = (t_xy){XPUT + POS_X, YPUT + POS_Y};
	else if (mlx->projection == 2)
		there = (t_xy){XISO + POS_X, YISO + POS_Y};
	return (there);

void    bresenhamen(float x, float y, float x1, float y1, t_fdf *fdf)
{
    float x_step;
    float y_step;
    int max;
    int z = fdf->z[y][x];
    int z1 = fdf->z[y1][x1];

    x*=fdf->zoom;
    ...
    fdf->color = (z || z1) ? 0xe80c0c : 0xffffff;
    x_step = x1-x;
    y_step = y1-y;
    isometric(&x, &y, &z);
    isometrix(&x1, &y1, &z1);
    max = MAX(MOD(x_step), MOD(y_step));
    x_step/=max;
    y-step/=max;
    while ((int)(x - x1) || (y - y1))
    {
        mlx_pixel_put(fdf->mlx, fdf->win, x, y, color);
        x += x_step;
        y+=y_step;
    }
}

void    draw_bres(*fdf)
{
    int x;
    int y;

    y = 0;
    while(y<fdf->y)
    {
        x =0;
        while (x < fdf->x
        {
            if (x < fdf->x-1)
                bresenhamen(x,y,x+1,y,fdf);
            if(y<fdf->y-1)
                bresenhamen(x,y,x,y+1,fdf)
            x++;
        }
        y++;
    }
}

//catch 'esc' or '->' '<-' and react
int deal_key(int key, *fdf)
{
    //printf(key);
    if (keycode == 53)
	{
		mlx_destroy_image(((t_mlx *)param)->mlx_ptr, ((t_mlx *)param)->img);
		mlx_destroy_window(((t_mlx *)param)->mlx_ptr, ((t_mlx *)param)->win);
		exit(1);
	}
    if key = 126//(up)
    ....
    mlx_clear_window(fdf->mlx, fdf->win);
    draw_bres()...
    return(0);
}

void    fdf_draw(t_fdf **fdf)
{
    *fdf->mlx_ptr = mlx_init();
    *fdf->win_ptr = mlx_new_window(*fdf->mlx_ptr, 1000, 1000, "FDF");
    *fdf->zoom = 20;
    draw_bres(fdf);
    mlx_key_hook(*fdf->win_ptr, deal_key, fdf);
    mlx_loop(*fdf->mlx_ptr);
}