#include "../includes/fdf.h"

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

void    window(t_fdf *fdf, int width, int height, char *title)
{
    fdf->mlx_ptr = mlx_init();
    fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, width, height, title);
    draw(fdf);
    mlx_key_hook(fdf->win_ptr, deal_key, NULL);
    mlx_loop(fdf->mlx_ptr;)
}

//////

float	fmodule(float i)
{
	return (i < 0) ? -i : i;
}

void	line(t_dot a, t_dot b, t_dot *param)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	set_param(&a, &b, param);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = MAX(fmodule(step_x), fmodule(step_y));
	step_x /= max;
	step_y /= max;
	color = (b.z || a.z) ? 0xfc0345 : 0xBBFAFF;
	color = (b.z != a.z) ? 0xfc031c : color;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, a.x, a.y, color);
		a.x += step_x;
		a.y += step_y;
		if (a.x > param->win_x || a.y > param->win_y || a.y < 0 || a.x < 0)
			break ;
	}
}

void	draw(t_dot **matrix)
{
	int		y;
	int		x;

	print_menu(PRM);
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				line(matrix[y][x], matrix[y + 1][x], &PRM);
			if (!matrix[y][x].is_last)
				line(matrix[y][x], matrix[y][x + 1], &PRM);
			if (matrix[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
}