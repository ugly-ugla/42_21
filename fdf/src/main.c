#include "../includes/fdf.h"

void    print_usage(void)
{
    ft_putendl("usage: ./fdf filename");
}

int     malloc_error(void)
{
    ft_putendl("Malloc error");
    return (0);
}

/*
** 1) read map and fill data
** 2) bresenhamen algorithm
** 3) window algorithm (not an algo, just draw with std libfx funcs)
** 4) draw map with bresenhamen
** 5) bonuses I don't want to deal with now
** 6) error handling: argc == 2, file must exist
** 7) fix leaks: leaks a.out or leaks fdf in shell
*/

int     main(int ac, char **av)
{
    t_fdf **fdf;

    if (ac == 2) {
        if (!(fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
            return (malloc_error());
        fdf = read_map();
        window();
        draw(fdf);
    } else {
        print_usage();
    }
    return (0);
}
