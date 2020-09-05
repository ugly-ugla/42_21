#ifndef FDF_H
#define FDF_H

#include "./libft/includes/libft.h"
#include "./mlx/mlx.h"

#include <stdio.h>

typedef struct  s_fdf
{
    int     x;
    int     y;
    int     **z;
    char    *projection;

    shift_y ///смещения
    shift_x

    void    *mlx_ptr;
    void    *win_ptr;
}               t_fdf;


int             main(int ac, char **av);
void            fdf_exit(/*char ***map, t_fdf **fdf, */char *err, int e);
void            fdf_usage(void);
void            fdf_read_data(char **map, char *file);
void            fdf_initiate(t_fdf **fdf);
void            fdf_validate_data(char **map, t_fdf **fdf);
int             get_map_height(char *data);
int             find_invalid_symbol(char *data);
int             find_unequal_lines(char *data);
void            fdf_fill_map(char **map, t_fdf **fdf);
void            fdf_draw(t_fdf *fdf);

#endif