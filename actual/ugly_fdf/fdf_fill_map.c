#include "fdf.h"

void    fdf_fill_map(char **map, t_fdf **fdf)
{
    int     i;
    int     j;
    char    **tmp;

    if (!((*fdf)->z = (int **)malloc(sizeof(int *) * (*fdf)->y)))
        fdf_exit(/*&map, fdf, */"Malloc Error!", 1);
    ft_strrepl(*map, '\n', ' ');
    if (!(tmp = ft_strsplit(*map, ' ')))
        fdf_exit(/*&map, fdf, */"Cannot Split Data!", 3);
    i = -1;
    while (i++ < (*fdf)->y - 1)
    {
        if (!((*fdf)->z[i] = (int *)malloc(sizeof(int) * (*fdf)->x)))
            fdf_exit(/*&map, fdf, */"Malloc Error!", 1);
        j = -1;
        while (j++ < (*fdf)->x - 1)
        {            
            (*fdf)->z[i][j] = ft_atoi(*tmp);
            tmp++;
        }
    }
}