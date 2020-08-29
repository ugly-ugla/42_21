#include "fdf.h"

#define MAX(a,b) (a > b ? a : b)

#define ABS(a) (a < 0 ? -a : a)

void    isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.8);
    *y = (*x + *y) * sin(0.8) - z;
}

void    bresenhamen(int x, int y, int x1, int y1, fdf *data)
{
    float   x_step;
    float   y_step;
    int     max;
    int     z;
    int     z1;

    z = data->map[y][x];
    z1 = data->map[y1][x1];
    x *= data->zoom;
    y *= data->zoom;
    x1 *= data->zoom;
    y1 *= data->zoom;
    data->color = (z || z1) ? 0xc80c0c : 0xffffff;
    x_step = x1 - x;
    y_step = y1 - y;
    isometric(&x, &y, z);
    isometric(&x1, &y1, z1);
    max = MAX(ABS(x_step), ABS(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
        x += x_step;
        y +=y_step;
    }
}

void    draw(fdf *data)
{
    int     x;
    int     y;

    y = 0;
    while (y < data->y)
    {
        x = 0;
        while (x < data->x)
        {
            if (x < data->x - 1)
                bresenhamen(x, y, x + 1, y, data);
            if (y < data->y - 1)
                bresenhamen(x, y, x, y + 1, data);
            ++x;
        }
        ++y;
    }
}
