#include "./fdf.h"

void    free_fdf(t_fdf **fdf)
{
    int     i;

    i = 0;
    (*fdf)->x = 0;
    printf("sdfsdf\n");
    while (i < (*fdf)->y - 1)
    {
        ft_memdel((void**)&(*fdf)->z[i]);
        i++;
        
    }
    free(*(*fdf)->z);
    (*fdf)->y = 0;
}

void    fdf_exit(/*char ***map, t_fdf **fdf, */char *error, int e)
{
    /*if (*map)
        ft_strdel(*map);
    free(*map);
    if (fdf != NULL)
        free_fdf(fdf);
    free(*fdf);
    printf("del fdf\n");*/
    if (error)
        printf("%s\n", error);
    exit(e);
}

void    fdf_usage(void)
{
    printf("usage: ./fdf filename\n");
    exit(0);
}

void    fdf_initiate(t_fdf **fdf, char *p_type)
{
    (*fdf)->x = 0;
    (*fdf)->y = 0;
    (*fdf)->z = NULL;

    (*fdf)->projection = "isometric";
}

int     main(int ac, char **av)
{
    t_fdf   *fdf;
    char    **map;

    if (ac > 1)
    {
        if (!(map = (char **)malloc(sizeof(char *))))
            fdf_exit(/*NULL, NULL, */"Malloc Error!", 1);
        fdf_read_data(map, av[1]);
        if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
            fdf_exit(/*NULL, NULL, */"Malloc Error!", 1);
        fdf_initiate(&fdf, av[2]);
        fdf_validate_data(map, &fdf);
        fdf_fill_map(map, &fdf);
        fdf_draw(&fdf);
    }
    else
    {
        fdf_exit(/*NULL, NULL, */"Invalid Number Of Arguments!", 5);
        fdf_usage();
    }
    return (0);
}